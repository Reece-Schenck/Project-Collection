import java.util.Arrays;

public class QuickSort {
    String[] array;
    int comparisons;

    public QuickSort(String[] array){
        this.array = array;
        comparisons = 0;
    }

    //used class psudo code as a template, then modified into java with my unique classes and methods
    public void sort(String[] array, int lowI, int highI){
        long startTime = System.nanoTime();
        String temp;
        int tempIndex;
        if(lowI>=highI){
            return;
        }
        String pivot = array[highI];
        int leftP = lowI;
        int rightP = highI;
        while(leftP<rightP){
            /*
            reference codes(what the comparison looks like in psudeo code):
            while(array[leftP]<=pivot && leftP<rightP){
            while(array[rightP]>=pivot && leftP<rightP){

            .compareTo gives a positive or negative int depending on whether
            array[j] is less than or greater than array[jMin] respectivly
            gives 0 if they are equal

            found this solution of comparing strings through the link below:
            https://www.w3schools.com/java/ref_string_comparetoignorecase.asp
            */
            comparisons++;
            while(array[leftP].compareToIgnoreCase(pivot)<=0 && leftP<rightP){
                //comparisons++;
                leftP = leftP + 1;
            }
            comparisons++;
            while(array[rightP].compareToIgnoreCase(pivot)>=0 && leftP<rightP){
                //comparisons++;
                rightP = rightP - 1;
            }
            temp = array[leftP];
            array[leftP] = array[rightP];
            array[rightP] = temp;
        }
        tempIndex = leftP;
        leftP = highI;
        highI = tempIndex;

        sort(array, lowI, leftP-1);
        sort(array, leftP+1, highI);
    }

    //used for testing if array was actually sorted
    public String[] getArray(){
        return array;
    }

    //used for getting the number of comparisons
    public int getComparisons(){
        return comparisons;
    }
}
