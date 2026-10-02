import java.util.HashMap;
import java.util.Map;

public class sample_0724 {
    public static int align(String seq1, String seq2, int i, int j, Map<String, Integer> memo) {
        if (i == 0 || j == 0) {
            return 0;
        }
        String key = i + "," + j;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        int result;
        if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
            result = 1 + align(seq1, seq2, i - 1, j - 1, memo);
        } else {
            result = Math.max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo));
        }
        memo.put(key, result);
        return result;
    }

    public static int longest_common_subsequence(String seq1, String seq2) {
        Map<String, Integer> memo = new HashMap<>();
        return align(seq1, seq2, seq1.length(), seq2.length(), memo);
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        System.out.println(longest_common_subsequence(seq1, seq2));
    }
}