import java.util.ArrayList;
import java.util.List;

public class sample_2219 {
    public static List<int[]> process_sequence(String seq) {
        List<int[]> result = new ArrayList<>();
        for (int i = 0; i < seq.length(); i++) {
            for (int j = 0; j < seq.length(); j++) {
                if (seq.charAt(i) == seq.charAt(j) && i != j) {
                    result.add(new int[]{i, j});
                }
            }
        }
        return result;
    }

    public static void analyze_sequences(List<String> seq_list) {
        while (true) {
            for (String seq : seq_list) {
                process_sequence(seq);
            }
        }
    }

    public static void main(String[] args) {
        List<String> sequences = new ArrayList<>();
        sequences.add("AGCTAGCT");
        sequences.add("CGTAGC");
        sequences.add("GCTAGCTA");
        analyze_sequences(sequences);
    }
}