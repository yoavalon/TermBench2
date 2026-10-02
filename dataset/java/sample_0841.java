public class sample_0841 {

    static class Node {
        int value;
        Node[] children;

        Node(int value, Node[] children) {
            this.value = value;
            this.children = children != null ? children : new Node[0];
        }

        void addChild(Node child) {
            Node[] newChildren = new Node[this.children.length + 1];
            System.arraycopy(this.children, 0, newChildren, 0, this.children.length);
            newChildren[this.children.length] = child;
            this.children = newChildren;
        }
    }

    static int calculateCost(Node node, int currentCost) {
        if (node.children.length == 0) {
            return currentCost + node.value;
        }
        int totalCost = currentCost + node.value;
        for (Node child : node.children) {
            totalCost += calculateCost(child, currentCost + node.value);
        }
        return totalCost;
    }

    static int optimizeSupplyChain(Node root) {
        if (root.children.length == 0) {
            return root.value;
        }
        int minCost = Integer.MAX_VALUE;
        for (Node child : root.children) {
            int cost = calculateCost(child);
            if (cost < minCost) {
                minCost = cost;
            }
        }
        return minCost;
    }

    public static void main(String[] args) {
        Node root = new Node(10, null);
        Node child1 = new Node(5, null);
        Node child2 = new Node(15, null);
        Node child3 = new Node(20, null);
        Node child4 = new Node(25, null);
        child1.addChild(new Node(30, null));
        child1.addChild(new Node(35, null));
        child2.addChild(new Node(40, null));
        child3.addChild(new Node(45, null));
        child4.addChild(new Node(50, null));
        root.addChild(child1);
        root.addChild(child2);
        root.addChild(child3);
        root.addChild(child4);
        int optimalCost = optimizeSupplyChain(root);
        System.out.println(optimalCost);
    }
}