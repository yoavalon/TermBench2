import java.util.HashMap;
import java.util.Map;

public class sample_0743 {
    static int align(String seq1, String seq2, int i, int j, Map<String, Integer> memo) {
        if (i == 0 || j == 0) {
            return Math.max(i, j);
        }
        String key = i + "," + j;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
            memo.put(key, align(seq1, seq2, i - 1, j - 1, memo));
        } else {
            memo.put(key, 1 + Math.min(align(seq1, seq2, i - 1, j, memo), Math.min(align(seq1, seq2, i, j - 1, memo), align(seq1, seq2, i - 1, j - 1, memo))));
        }
        return memo.get(key);
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        Map<String, Integer> memo = new HashMap<>();
        System.out.println(align(seq1, seq2, seq1.length(), seq2.length(), memo));
    }
}