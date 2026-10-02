import java.util.HashMap;
import java.util.Map;

public class sample_1927 {

    public static int align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        int[][] matrix = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                int match = matrix[i - 1][j - 1] + (seq1.charAt(i - 1) == seq2.charAt(j - 1) ? 1 : 0);
                int delete = matrix[i - 1][j] - 1;
                int insert = matrix[i][j - 1] - 1;
                matrix[i][j] = Math.max(match, Math.max(delete, insert));
            }
        }
        return matrix[len1][len2];
    }

    public static Map<String, Integer> process_genomic_data(Map<String, Map<String, String>> data) {
        Map<String, Integer> result = new HashMap<>();
        for (Map.Entry<String, Map<String, String>> entry : data.entrySet()) {
            String key = entry.getKey();
            Map<String, String> value = entry.getValue();
            int aligned_score = align_sequences(value.get("sequence1"), value.get("sequence2"));
            result.put(key, aligned_score);
        }
        return result;
    }

    public static void main(String[] args) {
        Map<String, Map<String, String>> genomic_data = new HashMap<>();
        genomic_data.put("sample1", Map.of("sequence1", "ATCG", "sequence2", "ACGT"));
        genomic_data.put("sample2", Map.of("sequence1", "GGTC", "sequence2", "GTCA"));
        Map<String, Integer> processed_data = process_genomic_data(genomic_data);
        System.out.println(processed_data);
    }
}