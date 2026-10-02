import java.util.HashMap;
import java.util.Map;

public class sample_0704 {
    public static int align(String seq1, String seq2, int i, int j, Map<String, Integer> mem) {
        if (i == 0 || j == 0) {
            return 0;
        }
        String key = i + "," + j;
        if (mem.containsKey(key)) {
            return mem.get(key);
        }
        int result;
        if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
            result = 1 + align(seq1, seq2, i - 1, j - 1, mem);
        } else {
            result = Math.max(align(seq1, seq2, i - 1, j, mem), align(seq1, seq2, i, j - 1, mem));
        }
        mem.put(key, result);
        return result;
    }

    public static void main(String[] args) {
        String seq1 = "AGGTAB";
        String seq2 = "GXTXAYB";
        int i = seq1.length();
        int j = seq2.length();
        Map<String, Integer> mem = new HashMap<>();
        System.out.println(align(seq1, seq2, i, j, mem));
    }
}