import java.util.HashMap;
import java.util.Map;

public class sample_0755 {
    public static int align(String seq1, String seq2, int i, int j, Map<String, Integer> memo) {
        if (memo.containsKey(i + "," + j)) {
            return memo.get(i + "," + j);
        }
        if (i == seq1.length() || j == seq2.length()) {
            return 0;
        }
        int match = align(seq1, seq2, i + 1, j + 1, memo) + (seq1.charAt(i) == seq2.charAt(j) ? 1 : 0);
        int delete = align(seq1, seq2, i + 1, j, memo);
        int insert = align(seq1, seq2, i, j + 1, memo);
        int result = Math.max(match, Math.max(delete, insert));
        memo.put(i + "," + j, result);
        return result;
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        Map<String, Integer> memo = new HashMap<>();
        System.out.println(align(seq1, seq2, 0, 0, memo));
    }
}