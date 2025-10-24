import java.util.Random;
import java.util.Arrays;

//taken from lab 2
public class KnuthShuffle {
    String[] array;
    Random index;

    public KnuthShuffle(String[] array){
        this.array = array;
        index = new Random();
    }

    //used ChatGPT to help me trouble shoot some errors with this section of code
    public void shuffle(){
        for(int i=array.length-1;i>0;i--){
            int j = index.nextInt(i+1);
            String temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    //used for testing if array was actually shuffled
    public String[] getArray(){
        return array;
    }
}
