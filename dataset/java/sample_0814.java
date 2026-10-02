public class sample_0814 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }
    }

    static class Ledger {
        Node root;

        Ledger() {
            this.root = null;
        }

        void insert(int value) {
            if (this.root == null) {
                this.root = new Node(value);
            } else {
                this._insert(this.root, value);
            }
        }

        void _insert(Node node, int value) {
            if (value < node.value) {
                if (node.left != null) {
                    this._insert(node.left, value);
                } else {
                    node.left = new Node(value);
                }
            } else if (node.right != null) {
                this._insert(node.right, value);
            } else {
                node.right = new Node(value);
            }
        }
    }

    static class Consensus {
        Ledger ledger;

        Consensus(Ledger ledger) {
            this.ledger = ledger;
        }

        boolean validate() {
            return this._validate(this.ledger.root);
        }

        boolean _validate(Node node) {
            if (node == null) {
                return true;
            }
            if (node.left != null && node.left.value > node.value) {
                return false;
            }
            if (node.right != null && node.right.value < node.value) {
                return false;
            }
            return this._validate(node.left) && this._validate(node.right);
        }
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        for (int i = 0; i < 100; i++) {
            ledger.insert(i);
        }
        Consensus consensus = new Consensus(ledger);
        System.out.println(consensus.validate());
    }
}