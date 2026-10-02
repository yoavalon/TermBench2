import java.util.ArrayList;
import java.util.List;

public class sample_1374 {
    public static int align_sequences(String seq1, String seq2) {
        int len1 = seq1.length();
        int len2 = seq2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }

    public static List<Integer> process_data(List<String[]> data) {
        List<Integer> results = new ArrayList<>();
        for (String[] pair : data) {
            int score = align_sequences(pair[0], pair[1]);
            results.add(score);
        }
        return results;
    }

    public static void main(String[] args) {
        List<String[]> data = new ArrayList<>();
        data.add(new String[]{"AGGTAB", "GXTXAYB"});
        data.add(new String[]{"ABCDGH", "AEDFHR"});
        data.add(new String[]{"XYZ", "XYZ"});
        List<Integer> output = process_data(data);
        System.out.println(output);
    }
}