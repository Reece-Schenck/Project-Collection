import java.util.Arrays;

public class InsertionSort {
    String[] array;
    
    public InsertionSort(String[] array){
        this.array = array;
    }

    //taken from lab 2
    public void sort(){
        long startTime = System.nanoTime();
        int comparisons = 0;
        int i = 1;
        int j;

        while(i < array.length){
            j = i;
            /*
            reference code(what the comparison looks like in psudeo code):
            while(j>0 && array[j-1]>array[j]){

            .compareTo gives a positive or negative int depending on whether
            array[j] is less than or greater than array[jMin] respectivly
            gives 0 if they are equal

            found this solution of comparing strings through the link below:
            https://www.w3schools.com/java/ref_string_comparetoignorecase.asp
            */
            while(j>0 && array[j-1].compareToIgnoreCase(array[j]) > 0){
                comparisons++;
                String temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                j = j - 1;
            }
            i = i + 1;
        }
        //prints the time(in nanoseconds aka μs) & number of comparisons
        long endTime = System.nanoTime();
        long elapsedTime = endTime - startTime;
        System.out.println("Insertion Sort:");
        System.out.println("Number of comparisons: " + comparisons);
        //The symbol 'μ' woldn't show up so I removed it
        System.out.println("Sorting time in nanoseconds: " + elapsedTime);
    }

    //used for testing if array was actually sorted
    public String[] getArray(){
        return array;
    }
}
