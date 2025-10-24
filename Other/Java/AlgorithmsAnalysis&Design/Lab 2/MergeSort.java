import java.util.Arrays;

public class MergeSort {
    String[] array;
    int comparisons;

    public MergeSort(String[] array){
        this.array = array;
        comparisons = 0;
    }

    //used class psudo code as a template, then modified into java with my unique classes and methods
    public void sort(String[] array){
        comparisons = 0;
        int len = array.length;
        if(len<2){
            return;
        }
        int mid = len / 2;
        /*
        reference code(what the comparison looks like in psudeo code):
        String[] left = array[0, mid-1];
        String[] right = array[mid, len];

        I used ChatGPT to help me create the left and right arrays
        specifically through the Arrays.copyOfRange command
        */
        //.copyOfRange(array, inclusive, exclusive)
        String[] left = Arrays.copyOfRange(array, 0, mid);
        String[] right = Arrays.copyOfRange(array, mid, len);

        sort(left);
        sort(right);

        merge(array, left, right);
    }

    public void merge(String[] array, String[] left, String[] right){
        int lenL = left.length;
        int lenR = right.length;
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<lenL && j<lenR){
            /*
            reference code(what the comparison looks like in psudeo code):
            if(left[i] <= right[i]){

            .compareTo gives a positive or negative int depending on whether
            array[j] is less than or greater than array[jMin] respectivly
            gives 0 if they are equal

            found this solution of comparing strings through the link below:
            https://www.w3schools.com/java/ref_string_comparetoignorecase.asp
            */
            comparisons++;
            if(left[i].compareToIgnoreCase(right[i]) <= 0){
                array[k] = left[i];
                i++;
            }else{
                array[k] = right[j];
                j++;
            }
            k++;
        }
        while(i<lenL){
            array[k] = left[i];
            i++;
            k++;
        }
        while(j<lenR){
            array[k] = right[j];
            j++;
            k++;
        }
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
