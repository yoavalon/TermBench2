import java.util.ArrayList;
import java.util.List;

public class sample_2085 {

    static class Sequencer {
        List<Character> sequence;
        int length;

        Sequencer(String sequence) {
            this.sequence = new ArrayList<>();
            for (char c : sequence.toCharArray()) {
                this.sequence.add(c);
            }
            this.length = sequence.length();
        }

        int align(Sequencer other) {
            int score = 0;
            for (int i = 0; i < Math.min(this.length, other.length); i++) {
                if (this.sequence.get(i) == other.sequence.get(i)) {
                    score += 1;
                }
            }
            return score;
        }

        List<Double> normalize() {
            List<Double> normalized = new ArrayList<>();
            for (int x : sequence) {
                normalized.add((double) x / this.length);
            }
            return normalized;
        }
    }

    static class Aligner {
        List<String> sequences;
        List<Sequencer> sequencers;

        Aligner(List<String> sequences) {
            this.sequences = sequences;
            this.sequencers = new ArrayList<>();
            for (String seq : sequences) {
                this.sequencers.add(new Sequencer(seq));
            }
        }

        List<Integer> pairwise_alignment() {
            List<Integer> scores = new ArrayList<>();
            for (int i = 0; i < sequencers.size(); i++) {
                for (int j = i + 1; j < sequencers.size(); j++) {
                    int score = sequencers.get(i).align(sequencers.get(j));
                    scores.add(score);
                }
            }
            return scores;
        }

        double average_score() {
            int total = 0;
            for (int score : pairwise_alignment()) {
                total += score;
            }
            return (double) total / sequencers.size();
        }
    }

    public static void main(String[] args) {
        List<String> sequences = List.of("ATCG", "ATCC", "ATCGT", "ATCGA");
        Aligner aligner = new Aligner(sequences);
        double average_score = aligner.average_score();
        List<List<Double>> normalized_scores = new ArrayList<>();
        for (Sequencer seq : aligner.sequencers) {
            normalized_scores.add(seq.normalize());
        }
        System.out.println("Average Alignment Score: " + average_score);
        for (int i = 0; i < normalized_scores.size(); i++) {
            System.out.println("Normalized Sequence " + (i + 1) + ": " + normalized_scores.get(i));
        }
    }
}