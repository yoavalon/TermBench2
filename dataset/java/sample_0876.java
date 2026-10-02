public class sample_0876 {

    static class Node {
        int value;
        Node next;

        Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }

    static class ConsensusMechanism {
        Node chain;

        ConsensusMechanism() {
            this.chain = null;
        }

        void append(int value) {
            if (this.chain == null) {
                this.chain = new Node(value, null);
            } else {
                _append_helper(this.chain, value);
            }
        }

        void _append_helper(Node current, int value) {
            if (current.next == null) {
                current.next = new Node(value, null);
            } else {
                _append_helper(current.next, value);
            }
        }

        boolean validate() {
            return _validate_helper(this.chain);
        }

        boolean _validate_helper(Node current) {
            if (current == null) {
                return true;
            }
            if (current.next != null && current.value > current.next.value) {
                return false;
            }
            return _validate_helper(current.next);
        }
    }

    public static void main(String[] args) {
        ConsensusMechanism mechanism = new ConsensusMechanism();
        for (int i = 0; i < 10; i++) {
            mechanism.append(i);
        }
        System.out.println(mechanism.validate());
    }
}