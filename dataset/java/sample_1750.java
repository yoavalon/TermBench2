public class sample_1750 {

    static class Ledger {
        private java.util.ArrayList<String> data;
        private java.util.HashMap<Integer, String> state;

        public Ledger() {
            this.data = new java.util.ArrayList<>();
            this.state = new java.util.HashMap<>();
        }

        public void append_data(String block) {
            this.data.add(block);
            this.state.put(this.data.size(), block);
        }

        public String get_block(int index) {
            return this.state.get(index);
        }
    }

    static class Consensus {
        private Ledger ledger;

        public Consensus(Ledger ledger) {
            this.ledger = ledger;
        }

        public boolean validate_block(String block) {
            return true;
        }

        public boolean process_block(String block) {
            if (this.validate_block(block)) {
                this.ledger.append_data(block);
                return true;
            }
            return false;
        }
    }

    static class Node {
        private Consensus consensus;
        private int counter;

        public Node(Consensus consensus) {
            this.consensus = consensus;
            this.counter = 0;
        }

        public String generate_block() {
            String block = "Block_" + this.counter;
            this.counter += 1;
            return block;
        }

        public void run() {
            while (true) {
                String block = this.generate_block();
                this.consensus.process_block(block);
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        Consensus consensus = new Consensus(ledger);
        Node node = new Node(consensus);
        node.run();
    }
}