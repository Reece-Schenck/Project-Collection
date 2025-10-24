import java.util.ArrayList;

// Used ChatGPT to make the base graph class and then edited to fit my code
public class Graph {
    private int numVertices;
    private ArrayList<ArrayList<Integer>> adjList;
    
    public Graph(int numVertices){
        this.numVertices = numVertices;
        adjList = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < numVertices; i++){
            adjList.add(new ArrayList<Integer>());
        }
    }
    
    public void addEdge(int u, int v){
        adjList.get(u).add(v);
        adjList.get(v).add(u);
    }
    
    public matrix toMatrix(){
        matrix matrix = new matrix(numVertices, numVertices);
        for(int i = 0; i < numVertices; i++){
            for(int j = 0; j < adjList.get(i).size(); j++){
                int neighbor = adjList.get(i).get(j);
                matrix.set(i, neighbor, 1);
            }
        }
        return matrix;
    }

    public ArrayList<ArrayList<Integer>> toAdjList(){
        return adjList;
    }
}
