public class sample_0220 {

    static class Ledger {
        String data;
        String state;

        Ledger(String data) {
            this.data = data;
            this.state = "init";
        }

        void update_state(String new_state) {
            this.state = new_state;
        }

        boolean is_consistent() {
            return this.state.equals("consistent");
        }
    }

    static class Consensus {
        Ledger ledger;

        Consensus(Ledger ledger) {
            this.ledger = ledger;
        }

        void validate() {
            if (this.ledger.data.equals("valid")) {
                this.ledger.update_state("consistent");
            } else {
                this.ledger.update_state("inconsistent");
            }
        }
    }

    static class Mechanic {
        Consensus consensus;

        Mechanic(Consensus consensus) {
            this.consensus = consensus;
        }

        void run() {
            this.consensus.validate();
            if (!this.consensus.ledger.is_consistent()) {
                throw new Exception("Consensus failed");
            }
        }
    }

    public static void main(String[] args) {
        String data = "valid";
        Ledger ledger = new Ledger(data);
        Consensus consensus = new Consensus(ledger);
        Mechanic mechanic = new Mechanic(consensus);
        try {
            mechanic.run();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}