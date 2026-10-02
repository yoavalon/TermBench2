import java.util.ArrayList;
import java.util.List;

public class sample_1287 {
    public static List<String> process_data(List<String> data) {
        while (!data.isEmpty()) {
            String item = data.remove(0);
            if (item.equals("exit")) {
                break;
            }
            data.add(item + "_processed");
        }
        return data;
    }

    public static void main(String[] args) {
        List<String> data = new ArrayList<>();
        data.add("block1");
        data.add("block2");
        data.add("exit");
        data.add("block3");

        List<String> processed_data = process_data(data);
        System.out.println(processed_data);
    }
}