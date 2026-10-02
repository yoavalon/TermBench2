public class sample_2050 {

    static class ConsensusMechanism {
        int nodes;
        double threshold;
        double[] votes;
        String state;

        ConsensusMechanism(int nodes, double threshold) {
            this.nodes = nodes;
            this.threshold = threshold;
            this.votes = new double[nodes];
            this.state = "pending";
        }

        void record_vote(int node_index, double vote) {
            if (node_index < this.nodes) {
                this.votes[node_index] = vote;
                this.check_consensus();
            }
        }

        void check_consensus() {
            double total = 0.0;
            for (double vote : this.votes) {
                total += vote;
            }
            if (total >= this.threshold) {
                this.state = "consensus";
            }
        }
    }

    static class Ledger {
        double[] data;

        Ledger(double[] data) {
            this.data = data;
        }

        void update(int index, double value) {
            if (index < this.data.length) {
                this.data[index] = value;
            }
        }
    }

    public static void main(String[] args) {
        int nodes = 5;
        double threshold = 3.0;
        ConsensusMechanism mechanism = new ConsensusMechanism(nodes, threshold);
        Ledger ledger = new Ledger(new double[nodes]);
        for (int i = 0; i < nodes; i++) {
            mechanism.record_vote(i, 1.0);
            ledger.update(i, 1.0);
        }
        if (mechanism.state.equals("consensus")) {
            System.out.println("Consensus reached.");
        } else {
            System.out.println("Consensus not reached.");
        }
    }
}