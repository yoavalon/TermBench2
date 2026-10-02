import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class sample_0101 {
    public static void update_state(Map<String, Object> state, Map<String, String> frame) {
        int currentFrame = (int) state.get("frame");
        currentFrame += 1;
        state.put("frame", currentFrame);

        ArrayList<Map<String, String>> dataList = (ArrayList<Map<String, String>>) state.get("data");
        dataList.add(frame);
        state.put("data", dataList);
    }

    public static boolean check_boundary_conditions(Map<String, Object> state, int max_frames) {
        int currentFrame = (int) state.get("frame");
        if (currentFrame >= max_frames) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        int max_frames = 10;
        Map<String, Object> state = new HashMap<>();
        state.put("frame", 0);
        state.put("data", new ArrayList<Map<String, String>>());

        while (!check_boundary_conditions(state, max_frames)) {
            Map<String, String> frame = new HashMap<>();
            frame.put("id", String.valueOf(state.get("frame")));
            frame.put("value", "data_frame");
            update_state(state, frame);
        }
        System.out.println(state);
    }
}