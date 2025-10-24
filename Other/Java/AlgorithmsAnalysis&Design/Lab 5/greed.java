import java.util.ArrayList;
import java.util.List;

public class greed {
    // tracks total
    double total;

    // tracks where the highest was found
    int index;

    public greed(bag bag, List<spices> spices){
        total = 0;
        int space = bag.getCapacity();
        float highest = 0;
        while(space>0){
            for(int i=0;i<spices.size()-1;i++){
                if(spices.get(i).getPrice()>highest){
                    highest = spices.get(i).getPrice();
                    index = i;
                }
            }
            int amount = spices.get(index).getqty();
            while(amount>0){
                total = total + highest;
                space--;
                amount--;
                if(space == 0){
                    break;
                }
                // removes emptied spices
                if(amount == 0){
                    spices.remove(index);
                }
            }
            highest = 0;
        }
    }

    public double getTotal(){
        return total;
    }
}
