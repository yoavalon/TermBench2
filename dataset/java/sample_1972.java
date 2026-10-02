import java.util.ArrayList;
import java.util.List;

public class sample_1972 {
    public static List<Double> track_sequence(int frame_count, int precision) {
        List<Double> frames = new ArrayList<>();
        for (int i = 0; i < frame_count; i++) {
            double frame = (double) i / precision;
            frames.add(frame);
        }
        return frames;
    }

    public static List<Double> analyze_frames(List<Double> frames) {
        List<Double> result = new ArrayList<>();
        for (double frame : frames) {
            double processed_frame = Math.round(frame * 100000.0) / 100000.0;
            result.add(processed_frame);
        }
        return result;
    }

    public static void main(String[] args) {
        int frame_count = 100;
        int precision = 1000;
        List<Double> frames = track_sequence(frame_count, precision);
        List<Double> analyzed_frames = analyze_frames(frames);
        System.out.println(analyzed_frames);
    }
}