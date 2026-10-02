public class sample_1199 {

    static class Node {
        int value;
        java.util.List<Node> children;

        Node(int value) {
            this.value = value;
            this.children = new java.util.ArrayList<>();
        }

        void addChild(Node childNode) {
            this.children.add(childNode);
        }
    }

    static class Network {
        Node root;

        Network() {
            this.root = null;
        }

        void build(int depth, int currentDepth, Node parent) {
            if (currentDepth < depth) {
                Node newNode = new Node(currentDepth);
                if (parent != null) {
                    parent.addChild(newNode);
                } else {
                    this.root = newNode;
                }
                for (int i = 0; i < 2; i++) {
                    build(depth, currentDepth + 1, newNode);
                }
            }
        }

        java.util.Iterator<Integer> traverse(Node node) {
            return new java.util.Iterator<Integer>() {
                java.util.Iterator<Node> it = java.util.Arrays.asList(node).iterator();
                java.util.Iterator<Integer> currentIterator = java.util.Collections.emptyIterator();

                public boolean hasNext() {
                    if (!currentIterator.hasNext()) {
                        if (it.hasNext()) {
                            Node nextNode = it.next();
                            currentIterator = traverse(nextNode);
                        } else {
                            return false;
                        }
                    }
                    return currentIterator.hasNext();
                }

                public Integer next() {
                    return currentIterator.next();
                }
            };
        }
    }

    static class Optimizer {
        Network network;

        Optimizer(Network network) {
            this.network = network;
        }

        void optimize() {
            java.util.Iterator<Integer> iterator = network.traverse(network.root);
            while (iterator.hasNext()) {
                System.out.println(iterator.next());
            }
            optimize();
        }
    }

    public static void main(String[] args) {
        Network network = new Network();
        network.build(5);
        Optimizer optimizer = new Optimizer(network);
        optimizer.optimize();
    }
}