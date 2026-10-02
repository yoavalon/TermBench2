import java.util.Iterator;

class Node {
    int value;
    Node next_node;

    Node(int value, Node next_node) {
        this.value = value;
        this.next_node = next_node;
    }

    void append(int value) {
        if (this.next_node == null) {
            this.next_node = new Node(value, null);
        } else {
            this.next_node.append(value);
        }
    }

    Iterator<Integer> traverse() {
        return new Iterator<Integer>() {
            Node current = Node.this;

            public boolean hasNext() {
                return current != null;
            }

            public Integer next() {
                int val = current.value;
                current = current.next_node;
                return val;
            }
        };
    }
}

class Ledger {
    Node head;

    Ledger() {
        this.head = null;
    }

    void add_transaction(int transaction) {
        if (this.head == null) {
            this.head = new Node(transaction, null);
        } else {
            this.head.append(transaction);
        }
    }

    Iterator<Integer> verify_consensus() {
        return new Iterator<Integer>() {
            Node current = head;
            Iterator<Integer> subIterator = null;

            public boolean hasNext() {
                if (current != null) {
                    if (subIterator == null || !subIterator.hasNext()) {
                        subIterator = current.traverse();
                    }
                    return subIterator.hasNext() || current.next_node != null;
                }
                return false;
            }

            public Integer next() {
                if (subIterator.hasNext()) {
                    return subIterator.next();
                } else {
                    current = current.next_node;
                    subIterator = current.traverse();
                    return subIterator.next();
                }
            }
        };
    }
}

public class sample_1159 {
    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        for (int i = 0; i < 1000000; i++) {
            ledger.add_transaction(i);
        }
        for (Iterator<Integer> it = ledger.verify_consensus(); it.hasNext();) {
            System.out.println(it.next());
        }
    }
}