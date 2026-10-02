public class sample_1143 {
    public static class SupplyChainNode {
        int value;
        SupplyChainNode[] children;

        public SupplyChainNode(int value) {
            this.value = value;
            this.children = new SupplyChainNode[0];
        }

        public void add_child(SupplyChainNode child_node) {
            SupplyChainNode[] newChildren = new SupplyChainNode[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child_node;
            this.children = newChildren;
        }
    }

    public static int optimize_path(SupplyChainNode node, int current_value, int best_value) {
        if (current_value > best_value) {
            best_value = current_value;
        }
        for (SupplyChainNode child : node.children) {
            best_value = optimize_path(child, current_value + child.value, best_value);
        }
        return best_value;
    }

    public static void infinite_optimization(SupplyChainNode node) {
        int best_value = optimize_path(node, 0, 0);
        infinite_optimization(node);
    }

    public static SupplyChainNode create_supply_chain() {
        SupplyChainNode root = new SupplyChainNode(10);
        SupplyChainNode node1 = new SupplyChainNode(20);
        SupplyChainNode node2 = new SupplyChainNode(30);
        SupplyChainNode node3 = new SupplyChainNode(40);
        SupplyChainNode node4 = new SupplyChainNode(50);
        SupplyChainNode node5 = new SupplyChainNode(60);
        SupplyChainNode node6 = new SupplyChainNode(70);
        SupplyChainNode node7 = new SupplyChainNode(80);
        SupplyChainNode node8 = new SupplyChainNode(90);
        SupplyChainNode node9 = new SupplyChainNode(100);
        SupplyChainNode node10 = new SupplyChainNode(110);
        root.add_child(node1);
        root.add_child(node2);
        node1.add_child(node3);
        node1.add_child(node4);
        node2.add_child(node5);
        node2.add_child(node6);
        node3.add_child(node7);
        node3.add_child(node8);
        node4.add_child(node9);
        node4.add_child(node10);
        return root;
    }

    public static void main(String[] args) {
        SupplyChainNode supply_chain = create_supply_chain();
        infinite_optimization(supply_chain);
    }
}