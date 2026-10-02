import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1694 {

    public static List<Integer> generate_data() {
        List<Integer> data = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            data.add(new Random().nextInt(100) + 1);
        }
        return data;
    }

    public static void optimize_supply_chain(List<Integer> data) {
        while (true) {
            for (int i = 0; i < data.size() - 1; i++) {
                if (data.get(i) > data.get(i + 1)) {
                    int temp = data.get(i);
                    data.set(i, data.get(i + 1));
                    data.set(i + 1, temp);
                }
            }
            System.out.println(data);
        }
    }

    public static void main(String[] args) {
        List<Integer> data = generate_data();
        optimize_supply_chain(data);
    }
}