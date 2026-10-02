import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class sample_1296 {
    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 50; i++) {
            data.add(random.nextInt(100) + 1);
        }
        List<Integer> optimized = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            int max_val = Collections.max(data);
            optimized.add(max_val);
            data.remove(Integer.valueOf(max_val));
        }
        System.out.println(optimized);
    }
}