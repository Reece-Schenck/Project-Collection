import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        //Read and Write text files into arrays
        //same code from other labs, changed slightly for reading more files

        //1st read file

        //This wasn't working for me: 
        String filename = "magicitems.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 4\\magicitems.txt";

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

        String[] linesArrayMagic = lines.toArray(new String[lines.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for (String l : linesArrayMagic) {
        //    System.out.println(l);
        //}


        //2nd read file

        //This wasn't working for me: 
        String filename2 = "magicitems-find-in-bst.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename2 = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 4\\magicitems-find-in-bst.txt";

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

        String[] linesArrayFind = lines2.toArray(new String[lines2.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for (String l : linesArrayFind) {
        //    System.out.println(l);
        //}


        //3rd read file

        //This wasn't working for me: 
        String filename3 = "graphs1.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename3 = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 4\\graphs1.txt";

        ArrayList<String> lines3 = new ArrayList<String>();

        try {
            BufferedReader reader = new BufferedReader(new FileReader(filename3));
            String line = reader.readLine();
            while (line != null) {
                lines3.add(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        String[] linesArrayGraph = lines3.toArray(new String[lines3.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for (String l : linesArrayGraph) {
        //    System.out.println(l);
        //}


        //creates a binary search tree
        BinarySearchTree tree = new BinarySearchTree();

        //Creates the root node
        Node root = null;

        //adds items to the tree and prints out the paths
        //finding path is broken but IDK whats wrong or how to fix it
        for(int i=0;i<linesArrayMagic.length;i++){
            root = tree.insert(root, linesArrayMagic[i]);
            System.out.println("Path to " + linesArrayMagic[i] + ":");
            System.out.println(tree.getPath(root));
            //doesn't fix the issues of path finding
            //tree.clearPath(root);
        }
        
        //prints out the elements of the tree through in-order traversal
        //items are printed in order and are seperated by a '.'
        tree.inorderSort(root);


        for(int i=0;i<linesArrayFind.length;i++){
            tree.search(root, linesArrayFind[i]);
            System.out.println("");
        }
        tree.averageComp(linesArrayFind.length);
        tree.averageTime(linesArrayFind.length);

        /*
           takes information from the strings in graphs1.txt
           and turns them into usable arrays of strings
           that are stored in the array list splitArrays
        */

        // This code was taken from ChatGPT and then edited to work with strings
        // as well as the arrays and array lists needed to function in my code 
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

        //prints out the graphs as matrixs
        System.out.println("Matrix Form:");
        for(String[] splitArray : splitArrays){
            int vertexNum = 0;
            for(String str : splitArray){
                if(str.startsWith("add vertex")){
                    vertexNum++;
                }
            }
            // used for testing
            System.out.println("Graph with " + vertexNum + " vertexs");
            Graph graph = new Graph(vertexNum+1);
            for(String str : splitArray){
                int num1;
                int num2;
                if(str.startsWith("add edge")){
                    String[] split = str.split(" ");
                    // .parseInt was found here:
                    // https://www.freecodecamp.org/news/java-string-to-int-how-to-convert-a-string-to-an-integer/
                    num1 = Integer.parseInt(split[2]);
                    num2 = Integer.parseInt(split[4]);
                    graph.addEdge(num1, num2);
                }
            }
            matrix matrix = graph.toMatrix();
            matrix.print();
            System.out.println("");
        }

        // adjacency list and matrix could be combined but I seperated them to make it look nice when printed

        // prints the graphs as adjacency lists
        System.out.println("Adjacency List Form:");
        for(String[] splitArray : splitArrays){
            int vertexNum = 0;
            for(String str : splitArray){
                if(str.startsWith("add vertex")){
                    vertexNum++;
                }
            }
            // used for testing
            System.out.println("");
            System.out.println("Graph with " + vertexNum + " vertexs");
            Graph graph = new Graph(vertexNum+1);
            for(String str : splitArray){
                int num1;
                int num2;
                if(str.startsWith("add edge")){
                    String[] split = str.split(" ");
                    // .parseInt was found here:
                    // https://www.freecodecamp.org/news/java-string-to-int-how-to-convert-a-string-to-an-integer/
                    num1 = Integer.parseInt(split[2]);
                    num2 = Integer.parseInt(split[4]);
                    graph.addEdge(num1, num2);
                }
            }
            // used ChatGPT for minor formatting help
            ArrayList<ArrayList<Integer>> adjList = graph.toAdjList();
            for(int i=0; i<adjList.size(); i++){
                System.out.print(i + ": ");
                for(int j=0; j<adjList.get(i).size(); j++){
                    System.out.print(adjList.get(i).get(j) + " ");
                }
                System.out.println("");
            }
        }

        // the reason this is seperated instead of combined is that same as I stated before
        
        //makes the graph as a linked object
        System.out.println("");
        System.out.println("Linked Object Form:");
        int start = 1;
        double totalTimeDepth = 0;
        double totalTimeBreadth = 0;
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
            // used for testing
            System.out.println("");
            System.out.println("Graph with " + vertexNum + " vertexs");
            linkedGraph linked = new linkedGraph(splitArray, vertexNum+1);
            for(String str : splitArray){
                int num1;
                int num2;
                if(str.startsWith("add edge")){
                    String[] split = str.split(" ");
                    // .parseInt was found here:
                    // https://www.freecodecamp.org/news/java-string-to-int-how-to-convert-a-string-to-an-integer/
                    num1 = Integer.parseInt(split[2]);
                    num2 = Integer.parseInt(split[4]);
                    linked.addEdge(num1, num2);
                }
            }
            System.out.println("Depth first traversal: ");
            startTime = System.nanoTime();
            linked.depthFirstTraversal(start);
            endTime = System.nanoTime();
            elapsedTime = endTime - startTime;
            totalTimeDepth = totalTimeDepth + elapsedTime;
            System.out.println("Time in nanoseconds: ");
            System.out.println(elapsedTime);

            System.out.println("");

            System.out.println("Breadth first traversal: ");
            startTime = System.nanoTime();
            linked.breadthFirstTraversal(start);
            endTime = System.nanoTime();            
            elapsedTime = endTime - startTime;
            totalTimeBreadth = totalTimeBreadth + elapsedTime;
        
            System.out.println("");
            System.out.println("Time in nanoseconds: ");
            System.out.println(elapsedTime);
            System.out.println(" ");

            timesRun++;

            // breath first should almost always be faster, however it is close
        }
        double averageTimeDepth = totalTimeDepth / timesRun;
        System.out.println("Average depth first traversal time: ");
        System.out.format("%.2f%n", averageTimeDepth);

        double averageTimeBreadth = totalTimeBreadth / timesRun;
        System.out.println("Average breadth first traversal time: ");
        System.out.format("%.2f%n", averageTimeBreadth);
    }
}