public class sample_0561 {
    static class LedgerNode {
        int data;
        LedgerNode next_node;

        LedgerNode(int data, LedgerNode next_node) {
            this.data = data;
            this.next_node = next_node;
        }
    }

    static class LedgerList {
        LedgerNode head;

        LedgerList() {
            this.head = null;
        }

        void append(int data) {
            LedgerNode new_node = new LedgerNode(data, null);
            if (this.head == null) {
                this.head = new_node;
                return;
            }
            LedgerNode last_node = this.head;
            while (last_node.next_node != null) {
                last_node = last_node.next_node;
            }
            last_node.next_node = new_node;
        }

        void consensus(LedgerNode node, int round_number) {
            if (node == null) {
                return;
            }
            if (round_number % 2 == 0) {
                node.data += 1;
            } else {
                node.data -= 1;
            }
            this.consensus(node.next_node, round_number + 1);
        }
    }

    public static void main(String[] args) {
        LedgerList ledger = new LedgerList();
        for (int i = 0; i < 10; i++) {
            ledger.append(i);
        }
        LedgerNode node = ledger.head;
        int round_number = 0;
        while (true) {
            ledger.consensus(node, round_number);
            round_number += 1;
        }
    }
}