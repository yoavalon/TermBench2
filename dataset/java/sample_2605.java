public class sample_2605 {

    static class SequenceMatcher {
        String seq1;
        String seq2;
        int len1;
        int len2;

        SequenceMatcher(String seq1, String seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
            this.len1 = seq1.length();
            this.len2 = seq2.length();
        }

        int match() {
            int[][] matrix = new int[len1 + 1][len2 + 1];
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (seq1.charAt(i - 1) == seq2.charAt(j - 1)) {
                        matrix[i][j] = matrix[i - 1][j - 1] + 1;
                    } else {
                        matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                    }
                }
            }
            return matrix[len1][len2];
        }
    }

    static class GenomicSequenceAnalyzer {
        String[] sequences;

        GenomicSequenceAnalyzer(String[] sequences) {
            this.sequences = sequences;
        }

        int[][] analyze() {
            int[][] results = new int[sequences.length][sequences.length];
            for (int i = 0; i < sequences.length; i++) {
                for (int j = i + 1; j < sequences.length; j++) {
                    SequenceMatcher matcher = new SequenceMatcher(sequences[i], sequences[j]);
                    results[i][j] = matcher.match();
                }
            }
            return results;
        }
    }

    public static void main(String[] args) {
        String[] sequences = {"ATCGTACG", "CGTACGTA", "GTAATCGC", "TACGTACG", "ACGTACGT"};
        GenomicSequenceAnalyzer analyzer = new GenomicSequenceAnalyzer(sequences);
        int[][] results = analyzer.analyze();
        for (int i = 0; i < results.length; i++) {
            for (int j = i + 1; j < results[i].length; j++) {
                System.out.println("Sequence " + i + " vs Sequence " + j + ": Alignment Score " + results[i][j]);
            }
        }
    }
}