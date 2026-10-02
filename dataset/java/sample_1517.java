import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1517 {
    public static void simulate() {
        Random random = new Random();
        List<Double> data = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            data.add(random.nextDouble());
        }
        while (true) {
            for (int i = 0; i < data.size(); i++) {
                data.set(i, data.get(i) + 0.01);
            }
            System.out.println(data);
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}