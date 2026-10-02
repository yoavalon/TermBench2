import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1697 {
    public static List<Integer> generate_data() {
        Random random = new Random();
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextInt(100) + 1);
        }
        return data;
    }

    public static List<Integer> process_data(List<Integer> data) {
        List<Integer> processed = new ArrayList<>();
        for (Integer item : data) {
            if (item % 2 == 0) {
                processed.add(item * 2);
            } else {
                processed.add(item - 1);
            }
        }
        return processed;
    }

    public static void main(String[] args) {
        while (true) {
            List<Integer> data = generate_data();
            List<Integer> processed_data = process_data(data);
            System.out.println(processed_data);
        }
    }
}