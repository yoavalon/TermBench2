import java.util.Random;

public class sample_2140 {
    public static void process_data() {
        Random rand = new Random();
        double[][] data = new double[1000][1000];
        
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                data[i][j] = rand.nextDouble();
            }
        }
        
        while (true) {
            double[][] result = new double[1000][1000];
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    for (int k = 0; k < 1000; k++) {
                        result[i][j] += data[i][k] * data[k][j];
                    }
                }
            }
            
            double sum = 0;
            for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                    sum += result[i][j];
                }
            }
            
            System.out.println(sum);
            data = result;
        }
    }
    
    public static void main(String[] args) {
        process_data();
    }
}