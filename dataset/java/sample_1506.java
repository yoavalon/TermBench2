import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class sample_1506 {
    public static void main(String[] args) {
        track_sequence();
    }

    public static void track_sequence() {
        ArrayList<Map<String, Integer>> data = new ArrayList<>();
        while (true) {
            Map<String, Integer> frameData = new HashMap<>();
            frameData.put("frame", data.size());
            frameData.put("timestamp", data.size() * 1000);
            data.add(frameData);
            System.out.println(data.get(data.size() - 1));
        }
    }
}