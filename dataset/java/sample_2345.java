public class sample_2345 {

    static class LedgerNode {
        double value;
        LedgerNode next;

        LedgerNode(double value) {
            this.value = value;
            this.next = null;
        }

        void set_next(LedgerNode node) {
            this.next = node;
        }
    }

    static class LedgerChain {
        LedgerNode head;

        LedgerChain() {
            this.head = null;
        }

        void append(double value) {
            LedgerNode new_node = new LedgerNode(value);
            if (this.head == null) {
                this.head = new_node;
            } else {
                LedgerNode current = this.head;
                while (current.next != null) {
                    current = current.next;
                }
                current.set_next(new_node);
            }
        }

        double calculate_consensus() {
            LedgerNode current = this.head;
            double sum_values = 0;
            int count = 0;
            while (current != null) {
                sum_values += current.value;
                count += 1;
                current = current.next;
            }
            if (count > 0) {
                return sum_values / count;
            }
            return 0;
        }
    }

    static double simulate_ledger_operations() {
        LedgerChain ledger = new LedgerChain();
        for (int i = 0; i < 1000; i++) {
            ledger.append((double) i / 3);
        }
        return ledger.calculate_consensus();
    }

    public static void main(String[] args) {
        while (true) {
            double result = simulate_ledger_operations();
            System.out.println("Consensus value: " + result);
        }
    }
}