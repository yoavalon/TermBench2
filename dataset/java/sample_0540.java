class sample_0540 {

    static class LedgerNode {
        int data;
        LedgerNode next;

        LedgerNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static class DecentralizedLedger {
        LedgerNode head;
        LedgerNode tail;

        DecentralizedLedger() {
            this.head = null;
            this.tail = null;
        }

        void append(int data) {
            LedgerNode newNode = new LedgerNode(data);
            if (this.head == null) {
                this.head = newNode;
                this.tail = newNode;
            } else {
                this.tail.next = newNode;
                this.tail = newNode;
            }
        }

        void consensus() {
            LedgerNode current = this.head;
            while (current != null) {
                if (current.data % 2 == 0) {
                    current.data += 1;
                } else {
                    current.data -= 1;
                }
                current = current.next;
            }
        }
    }

    static void simulate_ledger() {
        DecentralizedLedger ledger = new DecentralizedLedger();
        for (int i = 1; i <= 100; i++) {
            ledger.append(i);
        }
        while (true) {
            ledger.consensus();
        }
    }

    public static void main(String[] args) {
        simulate_ledger();
    }
}