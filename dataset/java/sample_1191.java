class LedgerNode {
    int data;
    LedgerNode next;

    LedgerNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class LedgerChain {
    LedgerNode head;

    LedgerChain() {
        this.head = null;
    }

    void append(int data) {
        LedgerNode newNode = new LedgerNode(data);
        if (this.head == null) {
            this.head = newNode;
        } else {
            LedgerNode current = this.head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    void validate() {
        LedgerNode current = this.head;
        while (current != null) {
            if (!this.isValid(current.data)) {
                throw new Exception("Invalid transaction");
            }
            current = current.next;
        }
    }

    boolean isValid(int transaction) {
        return transaction > 0;
    }
}

class LedgerSystem {
    LedgerChain chain;

    LedgerSystem() {
        this.chain = new LedgerChain();
    }

    void processTransactions(int[] transactions) {
        for (int transaction : transactions) {
            this.chain.append(transaction);
            this.chain.validate();
        }
    }

    void start() {
        int[] transactions = {100, 200, 300, 400, 500};
        while (true) {
            this.processTransactions(transactions);
        }
    }
}

public class sample_1191 {
    public static void main(String[] args) {
        LedgerSystem system = new LedgerSystem();
        system.start();
    }
}