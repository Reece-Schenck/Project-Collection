import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;
import java.util.List;

public class Main {
    
    public static void main(String[] args) {
        //Read and Write text file into an array

        //This wasn't working for me: 
        String filename = "magicitems.txt";

        //It only worked when hard coded, so this is what I used for testing:
        //String filename = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 2\\magicitems.txt";

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

        String[] linesArray = lines.toArray(new String[lines.size()]);
        //prints out the read lines, used for testing
        //System.out.println("Lines read from file:");
        //for (String l : linesArray) {
        //    System.out.println(l);
        //}


        //insertion sort
        InsertionSort insert = new InsertionSort(linesArray);
        insert.sort();
        String[] sorted = insert.getArray();
        System.out.println(Arrays.toString(sorted));

        System.out.println(" \n");


        //initializes shuffler and shuffles
        KnuthShuffle shuffler = new KnuthShuffle(sorted);
        shuffler.shuffle();
        String[] shuffledArray = shuffler.getArray();
        //System.out.println(Arrays.toString(shuffledArray));

        /*  
        I then use this shuffled array and put
        the first 42 target items into a new array.
        The shuffler essentially randomizes the list so 
        the first 42 items can be considered to be random
        */

        //Found copyOfRange from:
        //https://www.geeksforgeeks.org/java-util-arrays-copyofrange-java/

        //copy elements from shuffledArray from index 0(inclusive) to 42(exclusive)
        String[] targetElements = Arrays.copyOfRange(shuffledArray, 0, 42);

        //used for testing
        //System.out.println("Length of targetElements Array: " + targetElements.length);
        //System.out.println("Target Elements: " + Arrays.toString(targetElements));


        //needed to create a new array to hold the sorted items after the knuth shuffle 
        //as trying to use the original sorted array led to numerous errors
        //This was the only way I could figure out how to solve them
        insert.sort();
        String[] sorted2 = insert.getArray();
        //used for testing
        //System.out.println(Arrays.toString(sorted2));

        System.out.println(" \n");

        //linear search
        System.out.println("Linear Search:");
        linearSearch linear = new linearSearch(sorted2);
        linear.search(sorted2, targetElements);

        System.out.println(" \n");

        //reasoning is the same as for linear search
        insert.sort();
        String[] sorted3 = insert.getArray();
        //used for testing
        //System.out.println(Arrays.toString(sorted3));

        System.out.println(" \n");

        //binary search
        //if commented out everything else works
        System.out.println("Binary Search:");
        binarySearch binary = new binarySearch(sorted3);
        binary.search(sorted3, targetElements);

        System.out.println(" \n");

        /*
        done print statement used for testing as:
        binary search seems to be running for very long
        amounts of time and thus done is never printed out
        sometimes binary search prints out a few comparisons but
        other times it doesn't manage to print anything out at all
        I don't know why this is or how to fix it
        */
        System.out.println("done");
        System.out.println("\n");

        //hashing
        System.out.println("Hashing:");

        //create hash table with size 250
        hashTable<String, Integer> hash = new hashTable<>(250);

        //lines is the array list of magic items before being converted to a string list
        //I used this because it was easier to implement and troubleshoot with ChatGPT
        for(int i=0;i<lines.size();i++){
            hash.put(lines.get(i), i);
        }

        //holds the 42 items gotten from the hash table
        List<String> retrieved = new ArrayList<>();
        List<Long> times = new ArrayList<>();
        List<Integer> allComparisons = new ArrayList<>();

        Random rand = new Random();

        long startTime;
        long endTime;
        long elapsedTime;
        double totalTime = 0;
        double averageTime;
        int comparisons = 0;
        int totalCompare = 0;
        double averageCompare;

        //gets 42 random items from magicItems 
        //and finds them in the hashing table
        //used ChatGPT for some help with to printing results
        for(int i=0;i<42;i++){
            int index = rand.nextInt(lines.size());
            String key = lines.get(index);
            //start search
            startTime = System.nanoTime();
            Integer value = hash.get(key);
            if(value != null){
                endTime = System.nanoTime();
                retrieved.add(key);
                //end search

                elapsedTime = endTime - startTime;
                totalTime = totalTime + elapsedTime;
                times.add(elapsedTime);

                comparisons = hash.getComparisons();
                totalCompare = totalCompare + comparisons;
                allComparisons.add(comparisons);
            }
        }

        //Prints the retrieved strings and times
        //The symbol 'μ' woldn't show up so I removed it
        System.out.println("Retrieved strings & search time in nanoseconds:");
        int index = 0;
        for(String str : retrieved){
            System.out.println(str + ": " + times.get(index));
            System.out.println("Number of comparisons: " + allComparisons.get(index));
            index++;
        }
        averageTime = totalTime/lines.size();
        averageCompare = totalCompare/42;
        System.out.println("Average comparisons:");
        //found .format from Bob Beechey from https://www.quora.com/How-do-I-cut-off-decimals-in-Java
        //it cuts the double's decimals down to 2 places without replacing or deleting the other places
        System.out.format("%.2f%n", averageCompare);
        System.out.println("Average time in nanoseconds:");
        System.out.format("%.2f%n", averageTime);
    }
}