class LedgerNode {
    float data;
    LedgerNode next;

    LedgerNode(float data) {
        this.data = data;
        this.next = null;
    }
}

class Blockchain {
    LedgerNode head;

    Blockchain() {
        this.head = null;
    }

    void add_block(float data) {
        LedgerNode new_node = new LedgerNode(data);
        if (this.head == null) {
            this.head = new_node;
        } else {
            LedgerNode current = this.head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new_node;
        }
    }

    boolean verify_chain() {
        LedgerNode current = this.head;
        while (current != null) {
            if (!this.validate_data(current.data)) {
                return false;
            }
            current = current.next;
        }
        return true;
    }

    boolean validate_data(float data) {
        return data > 0.0 && data < 1000.0;
    }
}

public class sample_2080 {
    public static void main(String[] args) {
        Blockchain blockchain = new Blockchain();
        for (int i = 0; i < 10; i++) {
            blockchain.add_block((float) i / 3.0f);
        }
        System.out.println(blockchain.verify_chain());
    }
}