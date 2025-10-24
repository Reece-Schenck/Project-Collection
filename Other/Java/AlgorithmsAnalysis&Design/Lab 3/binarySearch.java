import java.util.Arrays;

public class binarySearch {
    //the array that is being searched
    String[] array;

    public binarySearch(String[] array){
        this.array = array;
    }

    //use divide and conquer + class notes
    //print where target is found, don't have 2 exits
    //may not need recursion
    public void search(String[] array, String[] targetArray){
        int comparisons = 0;
        int totalCompare = 0;
        double averageCompare;
        //-1 means that the target is not in the array
        int targetLocation = -1;
        int midIndex = array.length/2;
        int endIndex = array.length;
        int temp;
        long startTime;
        long endTime;
        long elapsedTime;
        double totalTime = 0;
        double averageTime;

        for(int i=0;i<targetArray.length;i++){
            startTime = System.nanoTime();
            for(int j=0;j<endIndex;j++){
                if(targetArray[i].compareToIgnoreCase(array[midIndex]) == 0){
                    comparisons++;
                    targetLocation = midIndex;
                    j = endIndex;
                }else if(targetArray[i].compareToIgnoreCase(array[midIndex]) < 0){
                    comparisons++;
                    temp = midIndex;
                    endIndex = midIndex;
                    if(temp/2 > 0){
                        midIndex = temp/2;
                    }
                }else{
                    comparisons++;
                    j = midIndex;
                    //stops out of bounds errors
                    if(midIndex + (midIndex/2) < 666){
                        midIndex = midIndex + (midIndex/2);
                    }
                }
            }
            //may have to reset the timers
            endTime = System.nanoTime();
            System.out.println("Number of comparisons for target " + targetArray[i] + ": " + comparisons);
            System.out.println("Target location: " + targetLocation);
            elapsedTime = endTime - startTime;
            totalTime = totalTime + elapsedTime;
            //The symbol 'μ' woldn't show up so I removed it
            System.out.println("Search time in nanoseconds: " + elapsedTime);
            totalCompare = totalCompare + comparisons;
            comparisons = 0;
            targetLocation = -1;
            midIndex = array.length/2;
            //array.length-1 maybe?
            endIndex = array.length;
        }
        averageCompare = totalCompare/targetArray.length-1;
        averageTime = totalTime/targetArray.length-1;
        System.out.println("Average comparisons:");
        //found .format from Bob Beechey from https://www.quora.com/How-do-I-cut-off-decimals-in-Java
        //it cuts the double's decimals down to 2 places without replacing or deleting the other places
        System.out.format("%.2f%n", averageCompare);
        System.out.println("Average time in nanoseconds:");
        System.out.format("%.2f%n", averageTime);
    }
}
