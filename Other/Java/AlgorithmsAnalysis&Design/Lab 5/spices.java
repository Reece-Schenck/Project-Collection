public class spices {

    String name;
    float price;
    int qty;

    public spices(String name, float price, int qty) {
        this.name = name;
        this.price = price;
        this.qty = qty;
    }

    public String getName(){
        return name;
    }

    public float getPrice(){
        return price;
    }

    public int getqty(){
        return qty;
    }
}
