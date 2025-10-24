import java.util.*;

// I had trouble converting my last graph class from undirected to directed
// so I used chat help to start me off ands I edited and added from there
public class WeightedDirectedGraph {
    // ChatGPT used hashmaps so that's why I used them
    private Map<Integer, List<Edge>> adjList;
    
    // creates hashmap
    public WeightedDirectedGraph() {
        adjList = new HashMap<>();
    }
    
    // adds vertex
    public void addVertex(int v) {
        if(!adjList.containsKey(v)){
            adjList.put(v, new ArrayList<>());
        }
    }

    // returns the number of vertecies
    public int getNumVertices() {
        return adjList.size();
    }
    
    // adds edge taking in (source, destination, weight)
    // adds verticies if they haven't already been added
    public void addEdge(int src, int dest, int weight) {
        if(!adjList.containsKey(src)){
            addVertex(src);
        }
        if(!adjList.containsKey(dest)){
            addVertex(dest);
        }
        (adjList.get(src)).add(new Edge(src, dest, weight));
    }

    // returns the number of edges
    public List<Edge> getEdges(int u) {
        return adjList.get(u);
    }
    
    // ChatGPT used priority queue for this part so that is why it is used
    // This was the biggest part that ChatGPT helped me with for this class
    // very little was changed in the shortest path part
    public List<Integer> shortestPath(int source) {
        Map<Integer, Integer> dist = new HashMap<>();
        Map<Integer, Integer> prev = new HashMap<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();
        
        for(int v : adjList.keySet()){
            dist.put(v, Integer.MAX_VALUE);
            prev.put(v, null);
        }
        dist.put(source, 0);
        pq.offer(new Node(source, 0));
        
        while(!pq.isEmpty()){
            Node curr = pq.poll();
            int currDist = curr.dist;
            int currVertex = curr.vertex;
            
            if(currDist > dist.get(currVertex)){
                continue;
            }
            
            for(Edge e : adjList.get(currVertex)){
                int nextVertex = e.dest;
                int nextDist = currDist + e.weight;
                
                if(nextDist < dist.get(nextVertex)){
                    dist.put(nextVertex, nextDist);
                    prev.put(nextVertex, currVertex);
                    pq.offer(new Node(nextVertex, nextDist));
                }
            }
        }
        
        List<Integer> path = new ArrayList<>();
        int curr = 1;
        while(curr != source && prev.get(curr) != null){
            path.add(curr);
            curr = prev.get(curr);
        }
        path.add(source);
        Collections.reverse(path);
        return path;
    }
    
    // I left this untouched from what ChatGPT gave me
    private static class Node implements Comparable<Node> {
        private int vertex;
        private int dist;
        
        public Node(int v, int d) {
            vertex = v;
            dist = d;
        }
        
        public int compareTo(Node other) {
            return Integer.compare(dist, other.dist);
        }
    }
    
    // basic edge class that holds source destination and weight
    static class Edge {
        private int src;
        private int dest;
        private int weight;
        
        public Edge(int s, int d, int w) {
            src = s;
            dest = d;
            weight = w;
        }

        // gets the weight
        public int getWeight(){
            return weight;
        }

        // gets destination vertex
        public int getTo(){
            return dest;
        }
    }
}