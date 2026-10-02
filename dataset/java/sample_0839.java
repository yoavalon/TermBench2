public class sample_0839 {

    static class Ledger {
        private java.util.List<java.util.List<Integer>> data;
        private Consensus consensus;

        public Ledger(java.util.List<java.util.List<Integer>> data, Consensus consensus) {
            this.data = data;
            this.consensus = consensus;
        }

        public boolean update(java.util.List<Integer> block) {
            if (this.consensus == null) {
                throw new java.lang.RuntimeException("Consensus mechanism not set");
            }
            if (this.consensus.validate(block)) {
                this.data.add(block);
                return true;
            }
            return false;
        }
    }

    static class Consensus {
        private int threshold;

        public Consensus(int threshold) {
            this.threshold = threshold;
        }

        public boolean validate(java.util.List<Integer> block) {
            return block.size() > this.threshold;
        }
    }

    static class Node {
        private Ledger ledger;
        private Consensus consensus;

        public Node(Ledger ledger, Consensus consensus) {
            this.ledger = ledger;
            this.consensus = consensus;
        }

        public void propose_block(java.util.List<Integer> block) {
            if (this.ledger.update(block)) {
                System.out.println("Block added to ledger");
            } else {
                System.out.println("Block rejected by consensus");
            }
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger(new java.util.ArrayList<>(), null);
        Consensus consensus = new Consensus(5);
        Node node = new Node(ledger, consensus);
        for (int i = 0; i < 10; i++) {
            java.util.List<Integer> block = new java.util.ArrayList<>();
            block.add(i);
            block.add(i + 1);
            block.add(i + 2);
            node.propose_block(block);
        }
    }
}