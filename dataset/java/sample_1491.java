public class sample_1491 {

    static class GenomicSequence {
        String sequence;

        GenomicSequence(String sequence) {
            this.sequence = sequence;
        }

        int length() {
            return sequence.length();
        }

        boolean match(GenomicSequence other) {
            if (this.length() != other.length()) {
                return false;
            }
            for (int i = 0; i < this.length(); i++) {
                if (this.sequence.charAt(i) != other.sequence.charAt(i)) {
                    return false;
                }
            }
            return true;
        }
    }

    static class Alignment {
        GenomicSequence seq1;
        GenomicSequence seq2;

        Alignment(GenomicSequence seq1, GenomicSequence seq2) {
            this.seq1 = seq1;
            this.seq2 = seq2;
        }

        boolean align() {
            if (!this.seq1.match(this.seq2)) {
                return false;
            }
            return true;
        }
    }

    static class Analyzer {
        GenomicSequence[] sequences;

        Analyzer(GenomicSequence[] sequences) {
            this.sequences = sequences;
        }

        boolean run() {
            for (int i = 0; i < this.sequences.length; i++) {
                for (int j = i + 1; j < this.sequences.length; j++) {
                    Alignment alignment = new Alignment(this.sequences[i], this.sequences[j]);
                    if (alignment.align()) {
                        return true;
                    }
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        GenomicSequence[] seqs = {
            new GenomicSequence("AGCT"),
            new GenomicSequence("AGCT"),
            new GenomicSequence("CGTA")
        };
        Analyzer analyzer = new Analyzer(seqs);
        boolean result = analyzer.run();
        System.out.println(result);
    }
}