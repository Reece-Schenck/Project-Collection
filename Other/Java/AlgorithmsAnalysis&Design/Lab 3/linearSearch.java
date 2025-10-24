import java.util.Arrays;

public class linearSearch {
    //the array that is being searched
    String[] array;

    public linearSearch(String[] array){
        this.array = array;
    }

    public void search(String[] array, String[] targetArray){
        int comparisons = 0;
        int totalCompare = 0;
        double averageCompare;
        long startTime;
        long endTime;
        long elapsedTime;
        double totalTime = 0;
        double averageTime;

        for(int i=0;i<targetArray.length;i++){
            startTime = System.nanoTime();
            for(int j=0;j<array.length;j++){
                if(targetArray[i].compareToIgnoreCase(array[j]) == 0){
                    comparisons = j+1;
                    break;
                }
            }
            //may have to clear the timers
            endTime = System.nanoTime();
            System.out.println("Number of comparisons for target " + targetArray[i] + ": " + comparisons);
            elapsedTime = endTime - startTime;
            totalTime = totalTime + elapsedTime;
            //The symbol 'μ' woldn't show up so I removed it
            System.out.println("Search time in nanoseconds: " + elapsedTime);
            totalCompare = totalCompare + comparisons;
            comparisons = 0;
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
