import java.util.HashMap;
import java.util.Map;

public class sample_0151 {
    public static Map<String, Integer> initialize_sequence(String seq) {
        Map<String, Integer> data = new HashMap<>();
        data.put("sequence", seq);
        data.put("position", 0);
        return data;
    }

    public static int align_sequences(String seq1, String seq2) {
        Map<String, Integer> seq1_data = initialize_sequence(seq1);
        Map<String, Integer> seq2_data = initialize_sequence(seq2);
        while (seq1_data.get("position") < seq1_data.get("sequence").length() && seq2_data.get("position") < seq2_data.get("sequence").length()) {
            if (seq1_data.get("sequence").charAt(seq1_data.get("position")) == seq2_data.get("sequence").charAt(seq2_data.get("position"))) {
                seq1_data.put("position", seq1_data.get("position") + 1);
                seq2_data.put("position", seq2_data.get("position") + 1);
            } else {
                seq1_data.put("position", seq1_data.get("position") + 1);
            }
        }
        return seq1_data.get("position");
    }

    public static void main(String[] args) {
        String sequence1 = "AGCTAGCTAGCT";
        String sequence2 = "AGCTAGCTAGCT";
        int result = align_sequences(sequence1, sequence2);
        System.out.println(result);
    }
}