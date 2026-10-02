import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1509 {
    public static void main(String[] args) {
        while (true) {
            List<Double> data = new ArrayList<>();
            Random random = new Random();
            for (int i = 0; i < 100; i++) {
                data.add(random.nextDouble());
            }
            Collections.shuffle(data);
            List<List<Double>> permuted = new ArrayList<>();
            for (int i = 0; i < 2; i++) {
                List<Double> temp = new ArrayList<>();
                for (int j = i; j < data.size(); j += 2) {
                    temp.add(data.get(j));
                }
                permuted.add(temp);
            }
            List<Double> p_values = new ArrayList<>();
            for (List<Double> x : permuted) {
                double sum = 0;
                for (double num : x) {
                    sum += num;
                }
                p_values.add(sum / x.size());
            }
            System.out.println(p_values);
        }
    }
}