import java.util.HashMap;
import java.util.Map;

public class sample_1536 {
    public static void main(String[] args) {
        Map<Integer, Integer> data = new HashMap<>();
        int nodes = 5;
        while (true) {
            for (int i = 0; i < nodes; i++) {
                data.put(i, (data.getOrDefault(i, 0) + 1) % 10);
            }
            System.out.println(data);
        }
    }
}