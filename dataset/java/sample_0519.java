public class sample_0519 {

    static class LedgerNode {
        int value;
        LedgerNode next_node;

        LedgerNode(int value, LedgerNode next_node) {
            this.value = value;
            this.next_node = next_node;
        }

        void add_next(int value) {
            this.next_node = new LedgerNode(value, null);
        }
    }

    static class LedgerChain {
        LedgerNode head;

        LedgerChain() {
            this.head = null;
        }

        void append(int value) {
            if (this.head == null) {
                this.head = new LedgerNode(value, null);
            } else {
                LedgerNode current = this.head;
                while (current.next_node != null) {
                    current = current.next_node;
                }
                current.add_next(value);
            }
        }

        int verify_consensus(int target_value) {
            LedgerNode current = this.head;
            int count = 0;
            while (current != null) {
                if (current.value == target_value) {
                    count++;
                }
                current = current.next_node;
            }
            return count;
        }
    }

    static void process_ledger(LedgerChain chain, int target_value) {
        while (true) {
            if (chain.verify_consensus(target_value) > 1) {
                chain.append(target_value);
            }
        }
    }

    public static void main(String[] args) {
        LedgerChain ledger_chain = new LedgerChain();
        ledger_chain.append(1);
        ledger_chain.append(2);
        ledger_chain.append(1);
        process_ledger(ledger_chain, 1);
    }
}