/*
  This class is similar to the graph class as it does similar things  
  however, it requires some different functions that can't be easlity
  implemented into the graph class like I did with the matrix and adjacency list
  and so I am making this new class as to not make the other overly cluttered
*/

import java.util.LinkedList;
import java.util.Queue;

// everything up to and including addEdge is almost identical to the graph class
// the only major differences are the addition and use of the vertex class
// I had a lot of errors implementing this that I used ChatGPT for help quite a bit
public class linkedGraph {
    private int numVertices;
    private Vertex[] vertices;

    public linkedGraph(String[] array, int numVertices){
        this.numVertices = numVertices;
        vertices = new Vertex[numVertices];
        for(int i = 0; i < numVertices; i++){
            vertices[i] = new Vertex(i);
        }
    }

    public void addEdge(int u, int v){
        vertices[u].addEdge(vertices[v]);
        vertices[v].addEdge(vertices[u]);
    }

    /*
      ChatGPT helped me with the public and private searches
      as I was having numerous issues implementing them
      I edited them slightly but the bulk of the code was given by ChatGPT for this part
    */
    public void depthFirstTraversal(int start){
        boolean[] visited = new boolean[numVertices];
        depthFirstTraversal(vertices[start], visited);
        System.out.println("");
    }

    private void depthFirstTraversal(Vertex vertex, boolean[] visited){
        visited[vertex.id] = true;
        System.out.print(vertex.id + " ");
        for(Vertex neighbor : vertex.getNeighbors()){
            if(!visited[neighbor.id]){
                depthFirstTraversal(neighbor, visited);
            }
        }
    }

    // 
    public void breadthFirstTraversal(int start){
        // stores if a vertex has been visited
        boolean[] visited = new boolean[numVertices];
        Queue<Vertex> queue = new LinkedList<>();
        queue.add(vertices[start]);
        visited[start] = true;

        while(!queue.isEmpty()){
            // Retrieves and removes the queue head, breaks loop if empty
            Vertex vertex = queue.poll();
            System.out.print(vertex.id + " ");
            for(Vertex neighbor : vertex.getNeighbors()){
                if(!visited[neighbor.id]){
                    queue.add(neighbor);
                    visited[neighbor.id] = true;
                }
            }
        }
    }
}

// I used ChatGPT to help me trouble shoot my code and 
// it had the vertex class outside of linkedGraph on the same file
class Vertex {
    public int id;
    public LinkedList<Vertex> neighbors;

    public Vertex(int id){
        this.id = id;
        neighbors = new LinkedList<>();
    }

    public void addEdge(Vertex v){
        neighbors.add(v);
    }

    public LinkedList<Vertex> getNeighbors(){
        return neighbors;
    }
}
