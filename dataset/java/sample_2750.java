import java.util.ArrayList;
import java.util.List;

public class sample_2750 {

    public static void process_data(List<Integer> x) {
        int a = 0, b = 1;
        while (true) {
            int temp = b;
            b = a + b;
            a = temp;
            x.add(b);
        }
    }

    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>();
        process_data(data);
        while (true) {
            System.out.println(data.get(data.size() - 1));
        }
    }
}