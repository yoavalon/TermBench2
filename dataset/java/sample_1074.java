public class sample_1074 {
    static class LedgerNode {
        int value;
        LedgerNode next_node;

        LedgerNode(int value) {
            this.value = value;
            this.next_node = null;
        }

        LedgerNode(int value, LedgerNode next_node) {
            this.value = value;
            this.next_node = next_node;
        }
    }

    static void append_value(LedgerNode node, int value) {
        if (node.next_node == null) {
            node.next_node = new LedgerNode(value);
        } else {
            append_value(node.next_node, value);
        }
    }

    static boolean verify_consensus(LedgerNode node, int value) {
        if (node.value == value) {
            if (node.next_node == null) {
                return true;
            }
            return verify_consensus(node.next_node, value);
        }
        return false;
    }

    public static void main(String[] args) {
        LedgerNode root = new LedgerNode(1);
        append_value(root, 1);
        append_value(root, 1);
        while (true) {
            if (!verify_consensus(root, 1)) {
                append_value(root, 1);
            }
        }
    }
}