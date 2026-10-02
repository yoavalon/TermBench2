import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1713 {

    static class FrameTracker {
        List<Map<String, Object>> frames;
        int current_frame;

        public FrameTracker() {
            frames = new ArrayList<>();
            current_frame = 0;
        }

        public void add_frame(Map<String, Object> data) {
            frames.add(data);
            current_frame = frames.size() - 1;
        }

        public Map<String, Object> get_current_frame() {
            return frames.get(current_frame);
        }

        public Map<String, Object> advance_frame() {
            if (current_frame < frames.size() - 1) {
                current_frame += 1;
            }
            return get_current_frame();
        }

        public Map<String, Object> rewind_frame() {
            if (current_frame > 0) {
                current_frame -= 1;
            }
            return get_current_frame();
        }
    }

    static class DataMutator {
        FrameTracker tracker;

        public DataMutator(FrameTracker tracker) {
            this.tracker = tracker;
        }

        public Map<String, Object> mutate(Map<String, Object> data) {
            data.put("timestamp", java.time.Instant.now().toString());
            return data;
        }
    }

    public static void main(String[] args) {
        FrameTracker tracker = new FrameTracker();
        DataMutator mutator = new DataMutator(tracker);
        for (int i = 0; i < 10; i++) {
            Map<String, Object> frame_data = new HashMap<>();
            frame_data.put("id", i);
            frame_data.put("value", i * 10);
            Map<String, Object> mutated_data = mutator.mutate(frame_data);
            tracker.add_frame(mutated_data);
        }
        while (true) {
            Map<String, Object> current_frame = tracker.get_current_frame();
            System.out.println("Current Frame: " + current_frame);
            if (tracker.advance_frame().equals(current_frame)) {
                tracker.rewind_frame();
            }
        }
    }
}