import java.util.Arrays;

public class SelectionSort {
    String[] array;

    public SelectionSort(String[] array){
        this.array = array;
    }

    //used class psudo code as a template, then modified into java with my unique classes and methods
    //used ChatGPT to help fix errors with timer
    public void sort(){
        long startTime = System.nanoTime();
        int comparisons = 0;
        int i = 0;
        int jMin;
        int j;

        while(i<array.length){
            jMin = i;
            j = i + 1;
            while(j<array.length){
                /*
                reference code(what the comparison looks like in psudeo code):
                if(array[j] < array[jMin]){


                .compareTo gives a positive or negative int depending on whether
                array[j] is less than or greater than array[jMin] respectivly
                gives 0 if they are equal

                found this solution of comparing strings through the link below:
                https://www.w3schools.com/java/ref_string_comparetoignorecase.asp
                */
                comparisons++;
                if(array[j].compareToIgnoreCase(array[jMin]) < 0){
                    jMin = j;
                }
                j = j + 1;
            }
            if(jMin!=i){
                String temp = array[i];
                array[i] = array[jMin];
                array[jMin] = temp;
            }
            i = i + 1;
        }
        //prints the time(in nanoseconds aka μs) & number of comparisons
        long endTime = System.nanoTime();
        long elapsedTime = endTime - startTime;
        System.out.println("Selection Sort:");
        System.out.println("Number of comparisons: " + comparisons);
        //The symbol 'μ' woldn't show up so I removed it
        System.out.println("Sorting time in nanoseconds: " + elapsedTime);
    }

    //used for testing if array was actually sorted
    public String[] getArray(){
        return array;
    }
}
