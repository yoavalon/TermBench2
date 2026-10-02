import java.util.ArrayList;
import java.util.List;

public class sample_0181 {
    public static int align_sequences(String seq1, String seq2, int max_distance) {
        if (max_distance < 0) {
            return -1;
        }
        int distance = 0;
        int i = 0, j = 0;
        while (i < seq1.length() && j < seq2.length()) {
            if (seq1.charAt(i) != seq2.charAt(j)) {
                distance += 1;
                if (distance > max_distance) {
                    return -1;
                }
            }
            i += 1;
            j += 1;
        }
        return distance;
    }

    public static List<Integer> process_sequences(List<String> sequences, int max_distance) {
        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < sequences.size(); i++) {
            for (int j = i + 1; j < sequences.size(); j++) {
                int result = align_sequences(sequences.get(i), sequences.get(j), max_distance);
                results.add(result);
            }
        }
        return results;
    }

    public static void main(String[] args) {
        List<String> sequences = List.of("ATCG", "ACGG", "TACG", "GCTA");
        int max_distance = 2;
        System.out.println(process_sequences(sequences, max_distance));
    }
}