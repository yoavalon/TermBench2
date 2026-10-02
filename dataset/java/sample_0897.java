public class sample_0897 {

    static class Alignment {
        String seq1;
        String seq2;
        int len1;
        int len2;

        Alignment(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.len1 = seq1.length();
            this.len2 = seq2.length();
        }

        int score(int i, int j) {
            return seq1.charAt(i) == seq2.charAt(j) ? 1 : -1;
        }

        int[] align(int i, int j) {
            if (i == -1 || j == -1) {
                return new int[]{0, 0, 0};
            }
            int[] match = align(i - 1, j - 1);
            match[0] += score(i, j);
            int[] insert = align(i, j - 1);
            insert[0] -= 1;
            int[] delete = align(i - 1, j);
            delete[0] -= 1;
            if (match[0] >= insert[0] && match[0] >= delete[0]) {
                return new int[]{match[0], seq1.charAt(i) + match[1], seq2.charAt(j) + match[2]};
            } else if (insert[0] >= match[0] && insert[0] >= delete[0]) {
                return new int[]{insert[0], '_' + insert[1], seq2.charAt(j) + insert[2]};
            } else {
                return new int[]{delete[0], seq1.charAt(i) + delete[1], '_' + delete[2]};
            }
        }
    }

    public static void main(String[] args) {
        String sequence1 = "AGGTAB";
        String sequence2 = "GXTXAYB";
        Alignment alignment = new Alignment(sequence1, sequence2);
        int[] result = alignment.align(alignment.len1 - 1, alignment.len2 - 1);
        System.out.println("Aligned Sequence 1: " + new String(result, 1, result.length - 1));
        System.out.println("Aligned Sequence 2: " + new String(result, 2, result.length - 1));
    }
}