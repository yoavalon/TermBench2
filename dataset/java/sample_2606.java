public class sample_2606 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = i * i + i + 1;
        }
        return sequence;
    }

    public static int[][] align_sequences(int[] seq1, int[] seq2) {
        int len1 = seq1.length;
        int len2 = seq2.length;
        int[][] alignment = new int[len1 + 1][len2 + 1];
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 || j == 0) {
                    alignment[i][j] = 0;
                } else if (seq1[i - 1] == seq2[j - 1]) {
                    alignment[i][j] = alignment[i - 1][j - 1] + 1;
                } else {
                    alignment[i][j] = Math.max(alignment[i - 1][j], alignment[i][j - 1]);
                }
            }
        }
        return alignment;
    }

    public static int[] find_longest_common_subsequence(int[] seq1, int[] seq2) {
        int[][] alignment_matrix = align_sequences(seq1, seq2);
        int len1 = seq1.length;
        int len2 = seq2.length;
        int[] lcs = new int[alignment_matrix[len1][len2]];
        int index = lcs.length - 1;
        while (len1 > 0 && len2 > 0) {
            if (seq1[len1 - 1] == seq2[len2 - 1]) {
                lcs[index--] = seq1[len1 - 1];
                len1--;
                len2--;
            } else if (alignment_matrix[len1 - 1][len2] > alignment_matrix[len1][len2 - 1]) {
                len1--;
            } else {
                len2--;
            }
        }
        return lcs;
    }

    public static void main(String[] args) {
        int[] seq1 = generate_sequence(10);
        int[] seq2 = generate_sequence(12);
        int[] lcs = find_longest_common_subsequence(seq1, seq2);
        for (int i : lcs) {
            System.out.print(i + " ");
        }
    }
}