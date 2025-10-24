import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;
import java.util.List;
import java.util.*;

public class Main {

    /* 
      Edited the graphs2 file taking out the results comments
      This allows me to cleanly split the graphs apart from one another

      Lines Removed:
      -- Results. Check yours against these.
      -- 1 --> 2 cost is  2; path: 1 --> 4 --> 3 --> 2
      -- 1 --> 3 cost is  4; path: 1 --> 4 --> 3
      -- 1 --> 4 cost is  7; path: 1 --> 4
      -- 1 --> 5 cost is -2; path: 1 --> 4 --> 3 --> 2 --> 5

      also changed this line to avoid splitting errors:
      -- directed 7-vertex v1 -- the "Tyler" graph.
      to
      -- directed 7-vertex v1 aka the "Tyler" graph.

      also also made sure there was only one space between
      last edge and weight for the same reason


      Edited the spice file taking out the first comment
      Also removed the ';'s from the lnapsacks 
      and made all spaces size 1 for concistancy
      reasoning same as above

      Line removed:
      -- She who controls the spice controls the universe.
    */

    public static void main(String[] args) {
        //Read and Write text files into arrays
        //same code from other labs, changed slightly for reading graphs2 and spice

        //This wasn't working for me: 
        String filename = "graphs2.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 5\\graphs2.txt";

        ArrayList<String> lines = new ArrayList<String>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename));
            String line = reader.readLine();
            while (line != null) {
                lines.add(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[] linesArrayGraph = lines.toArray(new String[lines.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for(String l : linesArrayGraph){
        //    System.out.println(l);
        //}

        //This wasn't working for me: 
        String filename2 = "spice.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename2 = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 5\\spice.txt";

        ArrayList<String> lines2 = new ArrayList<String>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename2));
            String line = reader.readLine();
            while (line != null) {
                lines2.add(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // This code was taken from Lab4 and edited to fit graph2 and spice
        String[] linesArraySpice = lines2.toArray(new String[lines2.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for(String l : linesArraySpice){
        //    System.out.println(l);
        //}

        
        String keyPhraseSpice = "--";
        List<String[]> splitArraysSpice = new ArrayList<>();
        List<String> currentArraySpice = new ArrayList<>();
        for(String str : linesArraySpice){
            if(str.startsWith(keyPhraseSpice)){
                splitArraysSpice.add(currentArraySpice.toArray(new String[currentArraySpice.size()]));
                currentArraySpice.clear();
            }else{
                // gets rid of the comments above each new graph
                // also new graph line is not added to split array
                // found .startswith from https://docs.oracle.com/javase/tutorial/java/data/comparestrings.html
                if(str.startsWith(keyPhraseSpice) == false){
                    currentArraySpice.add(str);
                }
            }
        }
        // Adds the last array
        splitArraysSpice.add(currentArraySpice.toArray(new String[currentArraySpice.size()]));

        // for testing
        //System.out.println("Original Array: " + Arrays.toString(originalArray));
        //System.out.println("Original Array: " + Arrays.toString(linesArraySpice));

        // first index will always be a useless blank array because
        // of the removal of the comments leaving the array at size 0
        splitArraysSpice.remove(0);

        // for testing
        //System.out.println("Split Arrays:");
        //for(String[] splitArray : splitArraysSpice){
        //    System.out.println(Arrays.toString(splitArray));
        //}
        //System.out.println(Arrays.toString(splitArraysSpice.get(0)));


        /*
           takes information from the strings in graphs2.txt
           and turns them into usable arrays of strings
           that are stored in the array list splitArrays
        */

        
        String keyPhrase = "new graph";
        List<String[]> splitArrays = new ArrayList<>();
        List<String> currentArray = new ArrayList<>();
        for(String str : linesArrayGraph){
            if(str.equals(keyPhrase)){
                splitArrays.add(currentArray.toArray(new String[currentArray.size()]));
                currentArray.clear();
            }else{
                // gets rid of the comments above each new graph
                // also new graph line is not added to split array
                // found .startswith from https://docs.oracle.com/javase/tutorial/java/data/comparestrings.html
                if(str.startsWith("--") == false){
                    currentArray.add(str);
                }
            }
        }
        // Adds the last array
        splitArrays.add(currentArray.toArray(new String[currentArray.size()]));

        // for testing
        //System.out.println("Original Array: " + Arrays.toString(originalArray));
        //System.out.println("Original Array: " + Arrays.toString(linesArrayGraph));

        // first index will always be a useless blank array because
        // of the removal of the comments and array splits at 'new graph'
        splitArrays.remove(0);

        // for testing
        //System.out.println("Split Arrays:");
        //for(String[] splitArray : splitArrays){
        //    System.out.println(Arrays.toString(splitArray));
        //}
        //System.out.println(Arrays.toString(splitArrays.get(1)));


        // taken from lab 4 and edited to wrok with weighted and directed graphs
        // makes the directed and weighted graph
        System.out.println("");
        System.out.println("Directed and Weighted Graph:");
        // start is used for handeling starting vertecies of 1 or 0
        int start = 1;
        double totalTime = 0;
        long startTime;
        long endTime;
        long elapsedTime;
        int timesRun = 0;
        for(String[] splitArray : splitArrays){
            // start index defaults to 0
            int vertexNum = 0;
            for(String str : splitArray){
                // updates the start value for traversals based off the first index
                // this was the only way I could figure out to hanled having
                // starting vertecies of both 0 and 1 in the same file
                if(str.equals("add vertex 0")){
                    start = 0;
                }
                // used for testing
                //System.out.println("start value: " + start);
                if(str.startsWith("add vertex")){
                    vertexNum++;
                }
            }
            System.out.println("");
            // used for testing
            //System.out.println("Graph with " + vertexNum + " vertecies");
            WeightedDirectedGraph graph = new WeightedDirectedGraph();
            for(String str : splitArray){
                int num1;
                int num2;
                int weight;
                if(str.startsWith("add edge")){
                    String[] split = str.split(" ");
                    // used for testing
                    //System.out.println(split[5]);
                    // .parseInt was found here:
                    // https://www.freecodecamp.org/news/java-string-to-int-how-to-convert-a-string-to-an-integer/
                    num1 = Integer.parseInt(split[2]);
                    num2 = Integer.parseInt(split[4]);
                    weight = Integer.parseInt(split[5]);
                    graph.addEdge(num1, num2, weight);
                }
            }
            startTime = System.nanoTime();
            SSSP(graph, 1);
            endTime = System.nanoTime();
            elapsedTime = endTime - startTime;
            totalTime = totalTime + elapsedTime;
            System.out.println("Time in nanoseconds: ");
            System.out.println(elapsedTime);

            timesRun++;
        }
        System.out.println("");
        double averageTime = totalTime / timesRun;
        System.out.println("Average time in nanoseconds: ");
        System.out.format("%.2f%n", averageTime);


        
        // start knapsack
        System.out.println("");
        System.out.println("Knapsack:");

        double totalTime2 = 0;
        long startTime2;
        long endTime2;
        long elapsedTime2;
        int timesRun2 = 0;
        List<spices> allSpices = new ArrayList<>();
        List<bag> allBags = new ArrayList<>();
        for(String[] splitArraySpice : splitArraysSpice){
            for(String str : splitArraySpice){
                String name = "";
                float price = 0;
                int qty = 0;
                if(str.startsWith("spice")){
                    String[] spice1 = str.split(";");
                    for(String str2 : spice1){
                        if(str2.startsWith("spice name")){
                            String[] spiceData = str2.split(" ");
                            name = spiceData[3];
                        }
                        if(str2.startsWith("total_price")){
                            String[] spiceData = str2.split(" ");
                            price = Float.parseFloat(spiceData[2]);
                        }
                        if(str2.startsWith("qty")){
                            String[] spiceData = str2.split(" ");
                            qty = Integer.parseInt(spiceData[2]);
                        }
                        spices spice = new spices(name, price, qty);
                        allSpices.add(spice);
                    }
                }
            }

            for(String str : splitArraySpice){
                int capacity = 0;
                if(str.startsWith("knapsack")){
                    String[] bagData = str.split(" ");
                    capacity = Integer.parseInt(bagData[3]);
                    bag bag = new bag(capacity);
                    // used for testing
                    //System.out.println("bag added " + bag.getCapacity());
                    allBags.add(bag);
                }
            }
        }

        for(bag bag : allBags){
            startTime2 = System.nanoTime();
            System.out.println("Total for bag of size: " + bag.getCapacity());

            greed steal = new greed(bag , allSpices);
            System.out.println(steal.getTotal());

            endTime2 = System.nanoTime();
            elapsedTime2 = endTime2 - startTime2;
            totalTime2 = totalTime2 + elapsedTime2;
            System.out.println("Time in nanoseconds: ");
            System.out.println(elapsedTime2);

            timesRun2++;
        }

        System.out.println("");
        double averageTime2 = totalTime2 / timesRun2;
        System.out.println("Average time in nanoseconds: ");
        System.out.format("%.2f%n", averageTime2);
        
    }


    // caused errors when not placed here
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
                int v = edge.getTo()-1;
                // gets the weight
                int weight = edge.getWeight();
                
                if(!visited[v] && (dist[u] != Integer.MAX_VALUE) && (dist[u] + weight < dist[v])){
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.offer(v);
                }
            }
        }
    
        // Prints the results
        // print formatting from ChatGPT
        for(int i=1; i<n+1; i++){
            if(i != source){
                System.out.printf("Shortest path from %d to %d: cost=%d, path=", source, i, dist[i-1]);
                printPath(parent, i);
                System.out.println();
            }
        }
    }
    
    private static void printPath(int[] parent, int v) {
        if(v == -1){
            return;
        }
        printPath(parent, parent[v-1]);
        System.out.print(v + " ");
    }
}