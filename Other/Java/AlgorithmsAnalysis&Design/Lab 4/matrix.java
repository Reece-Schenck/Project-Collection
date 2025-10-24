// Used ChatGPT to help with some troubleshooting
public class matrix {
    private int numRows;
    private int numCols;
    private int[][] data;
    
    public matrix(int numRows, int numCols){
        this.numRows = numRows;
        this.numCols = numCols;
        data = new int[numRows][numCols];
    }
    
    public void set(int i, int j, int value){
        data[i][j] = value;
    }
    
    public void print(){
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                System.out.print(data[i][j] + " ");
            }
            System.out.println();
        }
    }
}