import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static Stack lifo;
    public static Queue fifo;
    public static boolean palindrome;
    public static LinkedList temp;

    public static void main(String[] args) {
        //Read and Write text file into an array
        //I was having some trouble getting the read/write to work so I tweaked some code from ChatGPT
        String filename = "C:\\Users\\goldh\\OneDrive\\Documents\\GitHub\\RSchenck-435\\Lab 1\\magicitems.txt";
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
        //prints out the read lines
        //System.out.println("Lines read from file:");
        //for (String l : linesArray) {
        //    System.out.println(l);
        //}

        //Splits up the strings to single characters
        //Then checks for palindromes

        System.out.println("Here are all the palindromes:");
        
        for (String l : linesArray) {
            String[] splitted = l.split("");
            for(String s : splitted){
                if(!" ".equals(s)){
                    //IDK why I'm getting this error:
                    //Exception in thread "main" java.lang.NullPointerException: Cannot invoke "Stack.push(String)"
                    //because "Main.lifo" is null at Main.main(Main.java:52)
                    lifo.push(s);
                    fifo.enqueue(s);
                    temp.addFront(s);
                }
            }
            //The length of both lifo and fifo will be the same
            int len = lifo.length();

            for (int i=0;i<len;i++){
                String popped = lifo.pop();
                String dequeued = fifo.dequeue();
                if(Objects.equals(popped, dequeued)){
                    palindrome = true;
                }else{
                    //The item won't be counted as a palindrome and ends the loop
                    //but the stack and queue will be fully deleted for the next pass
                    palindrome = false;
                    for (int j=i;j<len;j++){
                        lifo.pop();
                        fifo.dequeue();
                    }
                    i = len;
                }
            }

            //prints temp only if the item is a palindrome
            if (palindrome == true){
                temp.print();
            }
            //Clears temp
            for(int i=0;i<temp.length();i++){
                temp.deleteFront();
            }

        }
    }    
}