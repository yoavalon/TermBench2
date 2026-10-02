import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;

public class sample_1642 {

    static Iterator<Integer> track_sequence(List<Integer> sequence) {
        return new Iterator<Integer>() {
            int frame = 0;

            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                if (frame < sequence.size()) {
                    return sequence.get(frame++);
                } else {
                    frame = 0;
                    return sequence.get(frame++);
                }
            }
        };
    }

    static void process_frames(Iterator<Integer> generator) {
        while (generator.hasNext()) {
            System.out.println(generator.next());
        }
    }

    public static void main(String[] args) {
        List<Integer> sequence = new ArrayList<>();
        sequence.add(1);
        sequence.add(2);
        sequence.add(3);
        sequence.add(4);
        sequence.add(5);
        Iterator<Integer> generator = track_sequence(sequence);
        process_frames(generator);
    }
}