import java.util.LinkedList;

public class hashTable<K, V> {
    private int size;

    //I'm not fully sure if this is allowed but since we
    // are allowed to use arraylists for the read functionality
    //I'm using a premade linked list instead of my own
    //It is also what ChatGPT suggested to use so I did
    private LinkedList<Entry<K, V>>[] table;
    int comparisons = 0;
    
    public hashTable(int size){
        this.size = size;
        this.table = new LinkedList[size];
    }
    
    /*
    I guenuinly had no Idea how to do hashing so 
    I used ChatGPT a lot for the parts below:
    I used it to help me start the hashisng code(layout and some code itself)
    I used it to help me troubleshoot issues from the many errors I had and have
    And I used it to help me write some parts of code I genuinly had no clue how to even attempt
    */
    private int hashFunction(K key){
        return Math.abs(key.hashCode() % size);
    }
    
    public void put(K key, V value){
        int index = hashFunction(key);
        Entry<K, V> entry = new Entry<>(key, value);
        
        if(table[index] == null){
            table[index] = new LinkedList<>();
        }
        
        //Checks if key already exists
        for(Entry<K, V> e : table[index]){
            if(e.getKey().equals(key)){
                e.setValue(value);
                return;
            }
        }
        
        //If the key is not found, a new entry is added to the linked list
        table[index].add(entry);
    }
    
    public V get(K key){
        int index = hashFunction(key);
        
        if(table[index] == null){
            return null;
        }
        
        //Searches for an entry with given the key
        for(Entry<K, V> e : table[index]){
            comparisons++;
            if(e.getKey().equals(key)){
                return e.getValue();
            }
        }
        
        //If key is not found
        return null;
    }

    //returns the number of comparisons then resets the count
    public int getComparisons(){
        int temp = comparisons;
        comparisons = 0;
        return temp;
    }
    
    public void remove(K key){
        int index = hashFunction(key);
        
        if(table[index] == null){
            return;
        }
        
        //Searches for an entry with the given key and removes it
        for(Entry<K, V> e : table[index]){
            if(e.getKey().equals(key)){
                table[index].remove(e);
                return;
            }
        }
    }
    
    private static class Entry<K, V>{
        private K key;
        private V value;
        
        public Entry(K key, V value){
            this.key = key;
            this.value = value;
        }
        
        public K getKey(){
            return key;
        }
        
        public V getValue(){
            return value;
        }
        
        public void setValue(V value){
            this.value = value;
        }
    }
}