import java.util.*;

public class SSSP {
    public static void SSSP(WeightedDirectedGraph graph, int source){
        int n = graph.getNumVertices();
        
        // Initialize the distance and visited arrays
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;

        // Initialize the parent array
        int[] parent = new int[n];
        Arrays.fill(parent, -1);

        // Create a priority queue and add the source vertex
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(i -> dist[i]));
        pq.offer(source);

        // Runs the algorithm
        while(!pq.isEmpty()){
            int u = pq.poll();
            visited[u] = true;
            
            for(WeightedDirectedGraph.Edge edge : graph.getEdges(u)){
                // gets destination vertex
                int v = edge.getTo();
                // gets the weight
                int weight = edge.getWeight();
                
                if(!visited[v] && dist[u] != Integer.MAX_VALUE && dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.offer(v);
                }
            }
        }

        // Prints the results
        // print formatting from ChatGPT
        for(int i = 0; i < n; i++){
            if(i != source){
                System.out.printf("Shortest path from %d to %d: cost=%d, path=", source, i, dist[i]);
                printPath(parent, i);
                System.out.println();
            }
        }
    }

    private static void printPath(int[] parent, int v) {
        if(v == -1){
            return;
        }
        printPath(parent, parent[v]);
        System.out.print(v + " ");
    }
}