import java.util.List;

public class sample_1977 {
    public static double calculate_similarity(List<Character> seq1, List<Character> seq2) {
        int length = Math.min(seq1.size(), seq2.size());
        int identical = 0;
        for (int i = 0; i < length; i++) {
            if (seq1.get(i) == seq2.get(i)) {
                identical++;
            }
        }
        return (double) identical / length;
    }

    public static double normalize_score(double score) {
        return Math.round(score * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        List<Character> sequence_a = List.of('A', 'C', 'G', 'T', 'A', 'C', 'G', 'T', 'A', 'C', 'G', 'T');
        List<Character> sequence_b = List.of('A', 'C', 'G', 'T', 'A', 'C', 'G', 'T', 'A', 'C', 'G', 'A');
        double similarity_score = calculate_similarity(sequence_a, sequence_b);
        double normalized_score = normalize_score(similarity_score);
        System.out.println(normalized_score);
    }
}