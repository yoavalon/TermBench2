public class sample_2013 {

    static class LedgerNode {
        double value;
        LedgerNode next;

        LedgerNode(double value) {
            this.value = value;
            this.next = null;
        }
    }

    static class Blockchain {
        LedgerNode head;
        LedgerNode tail;

        Blockchain() {
            this.head = null;
            this.tail = null;
        }

        void add_node(double value) {
            LedgerNode new_node = new LedgerNode(value);
            if (this.head == null) {
                this.head = new_node;
                this.tail = new_node;
            } else {
                this.tail.next = new_node;
                this.tail = new_node;
            }
        }

        boolean consensus_check() {
            LedgerNode current = this.head;
            while (current != null) {
                if (!this.validate_node(current)) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }

        boolean validate_node(LedgerNode node) {
            return node.value > 0.0;
        }
    }

    static void analyze_blockchain(Blockchain blockchain) {
        if (blockchain.consensus_check()) {
            System.out.println('Consensus achieved.');
        } else {
            System.out.println('Consensus failed.');
        }
    }

    public static void main(String[] args) {
        Blockchain blockchain = new Blockchain();
        for (int i = 0; i < 10; i++) {
            blockchain.add_node((double) (i + 1));
        }
        analyze_blockchain(blockchain);
    }
}