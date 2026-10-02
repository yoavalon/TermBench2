class sample_2028 {

    static class LedgerNode {
        double data;
        LedgerNode next;

        LedgerNode(double data) {
            this.data = data;
            this.next = null;
        }
    }

    static class LedgerConsensus {
        LedgerNode head;
        LedgerNode tail;

        LedgerConsensus() {
            this.head = null;
            this.tail = null;
        }

        void add_node(double data) {
            LedgerNode new_node = new LedgerNode(data);
            if (this.head == null) {
                this.head = new_node;
                this.tail = new_node;
            } else {
                this.tail.next = new_node;
                this.tail = new_node;
            }
        }

        boolean validate_transactions() {
            LedgerNode current = this.head;
            while (current != null) {
                if (!is_transaction_valid(current.data)) {
                    return false;
                }
                current = current.next;
            }
            return true;
        }

        boolean is_transaction_valid(double transaction) {
            return transaction > 0;
        }
    }

    static boolean process_ledger(double[] transactions) {
        LedgerConsensus ledger = new LedgerConsensus();
        for (double transaction : transactions) {
            ledger.add_node(transaction);
        }
        return ledger.validate_transactions();
    }

    public static void main(String[] args) {
        double[] transactions = {1.1, 2.2, 3.3, 4.4, 5.5};
        boolean result = process_ledger(transactions);
        System.out.println(result);
    }
}