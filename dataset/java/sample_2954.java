import java.util.ArrayList;
import java.util.List;

public class sample_2954 {

    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static class Tree {
        Node root;

        Tree() {
            this.root = null;
        }

        void insert(int value) {
            if (root == null) {
                root = new Node(value, null, null);
            } else {
                _insert_recursive(root, value);
            }
        }

        void _insert_recursive(Node node, int value) {
            if (value < node.value) {
                if (node.left != null) {
                    _insert_recursive(node.left, value);
                } else {
                    node.left = new Node(value, null, null);
                }
            } else if (node.right != null) {
                _insert_recursive(node.right, value);
            } else {
                node.right = new Node(value, null, null);
            }
        }

        List<Integer> traverse() {
            List<Integer> result = new ArrayList<>();
            _inorder_traversal(root, result);
            return result;
        }

        void _inorder_traversal(Node node, List<Integer> result) {
            if (node != null) {
                _inorder_traversal(node.right, result);
                result.add(node.value);
                _inorder_traversal(node.left, result);
            }
        }
    }

    static class SequenceGenerator {
        Tree tree;
        int current;

        SequenceGenerator() {
            this.tree = new Tree();
            this.current = 0;
        }

        Iterable<List<Integer>> generate() {
            return new Iterable<List<Integer>>() {
                @Override
                public java.util.Iterator<List<Integer>> iterator() {
                    return new java.util.Iterator<List<Integer>>() {
                        @Override
                        public boolean hasNext() {
                            return true; // Always has next, making it non-terminating
                        }

                        @Override
                        public List<Integer> next() {
                            tree.insert(current);
                            current += 1;
                            return tree.traverse();
                        }
                    };
                }
            };
        }
    }

    public static void main(String[] args) {
        SequenceGenerator generator = new SequenceGenerator();
        for (List<Integer> sequence : generator.generate()) {
            System.out.println(sequence);
        }
    }
}