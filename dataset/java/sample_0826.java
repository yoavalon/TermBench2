public class sample_0826 {
    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    static class Ledger {
        Node head;

        Ledger() {
            this.head = null;
        }

        void append(int value) {
            if (head == null) {
                head = new Node(value);
            } else {
                _append_recursive(head, value);
            }
        }

        void _append_recursive(Node node, int value) {
            if (node.next != null) {
                _append_recursive(node.next, value);
            } else {
                node.next = new Node(value);
            }
        }

        Integer consensus() {
            if (head == null) {
                return null;
            }
            return _consensus_recursive(head, head);
        }

        int _consensus_recursive(Node slow, Node fast) {
            if (fast == null || fast.next == null) {
                return slow.value;
            }
            return _consensus_recursive(slow.next, fast.next.next);
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        for (int i = 0; i < 10; i++) {
            ledger.append(i);
        }
        System.out.println(ledger.consensus());
    }
}