public class sample_0832 {

    static class LedgerNode {
        int value;
        LedgerNode left;
        LedgerNode right;

        LedgerNode(int value, LedgerNode left, LedgerNode right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static class ConsensusMechanics {
        LedgerNode root;

        ConsensusMechanics(LedgerNode root) {
            this.root = root;
        }

        boolean validate(LedgerNode node) {
            if (node == null) {
                return true;
            }
            if (node.left != null && node.left.value > node.value) {
                return false;
            }
            if (node.right != null && node.right.value < node.value) {
                return false;
            }
            return validate(node.left) && validate(node.right);
        }

        void update(LedgerNode node, int new_value) {
            if (node == null) {
                return;
            }
            if (node.value < new_value) {
                node.value = new_value;
            }
            if (node.left != null) {
                update(node.left, new_value);
            }
            if (node.right != null) {
                update(node.right, new_value);
            }
        }
    }

    public static void main(String[] args) {
        LedgerNode root = new LedgerNode(10, new LedgerNode(5), new LedgerNode(15));
        ConsensusMechanics consensus = new ConsensusMechanics(root);
        System.out.println(consensus.validate(root));
        consensus.update(root.left, 7);
        System.out.println(consensus.validate(root));
        consensus.update(root.right, 3);
        System.out.println(consensus.validate(root));
    }
}