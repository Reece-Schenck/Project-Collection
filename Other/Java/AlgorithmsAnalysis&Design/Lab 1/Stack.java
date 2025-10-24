public class Stack {
    LinkedList list;

    public Stack(){
        this.list.root = null;
    }

    public void push(String value) {
        list.addEnd(value);
    }

    public String pop() {
        return list.deleteEnd();
    }

    public int length(){
        return list.length();
    }

    //public String peek(){
    //    
    //}
}
