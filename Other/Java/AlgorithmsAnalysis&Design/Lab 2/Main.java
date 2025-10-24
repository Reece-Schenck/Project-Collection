import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;

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

        //initializes shuffler and shuffles
        KnuthShuffle shuffler = new KnuthShuffle(linesArray);
        shuffler.shuffle();
        String[] shuffledArray = shuffler.getArray();
        //System.out.println(Arrays.toString(shuffledArray));

        //selection sort
        SelectionSort select = new SelectionSort(shuffledArray);
        select.sort();
        String[] sorted1 = select.getArray();
        //System.out.println(Arrays.toString(sorted1));

        System.out.println(" ");

        //shuffle again
        shuffler.shuffle();
        shuffledArray = shuffler.getArray();
        //System.out.println(Arrays.toString(shuffledArray));

        //insertion sort
        InsertionSort insert = new InsertionSort(shuffledArray);
        insert.sort();
        String[] sorted2 = insert.getArray();
        //System.out.println(Arrays.toString(sorted2));

        System.out.println(" ");

        //shuffle again
        shuffler.shuffle();
        shuffledArray = shuffler.getArray();
        //System.out.println(Arrays.toString(shuffledArray));  

        //merge sort
        //used ChatGPT to help fix errors with timer
        long startTime = System.nanoTime();
        MergeSort merge = new MergeSort(shuffledArray);
        merge.sort(shuffledArray);
        String[] sorted3 = merge.getArray();
        //System.out.println(Arrays.toString(sorted3));
        long endTime = System.nanoTime();
        long elapsedTime = endTime - startTime;
        System.out.println("Merge Sort:");
        System.out.println("Number of comparisons: " + merge.getComparisons());
        //The symbol 'μ' woldn't show up so I removed it
        System.out.println("Sorting time in nanoseconds: " + elapsedTime);

        System.out.println(" ");

        //shuffle again
        shuffler.shuffle();
        shuffledArray = shuffler.getArray();
        //System.out.println(Arrays.toString(shuffledArray));

        //quick sort
        //used ChatGPT to help fix errors with timer
        long startTime2 = System.nanoTime();
        QuickSort quick = new QuickSort(shuffledArray);
        quick.sort(shuffledArray, 0, shuffledArray.length-1);
        String[] sorted4 = quick.getArray();
        //System.out.println(Arrays.toString(sorted4));
        long endTime2 = System.nanoTime();
        long elapsedTime2 = endTime2 - startTime2;
        System.out.println("Quick Sort:");
        System.out.println("Number of comparisons: " + quick.getComparisons());
        //The symbol 'μ' woldn't show up so I removed it
        System.out.println("Sorting time in nanoseconds: " + elapsedTime2);
    }
}
