public class listItem {
    int value;
    listItem listItem;

    //item holds a value and is linked to another list item
    public listItem(int value, listItem listItem){
        this.value = value;
        this.listItem = listItem;
        getValue();
    }

    //gets value of node
    public int getValue(){
        return value;
    }
}