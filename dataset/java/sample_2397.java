class sample_2397 {

    static class Node {
        String value;
        Node left;
        Node right;

        Node(String value, Node left, Node right) {
            this.value = value;
            this.left = left;
            this.right = right;
        }
    }

    static int[] analyze_tree(Node node) {
        if (node == null) {
            return new int[]{0, 0};
        }
        int[] l_result = analyze_tree(node.left);
        int[] r_result = analyze_tree(node.right);
        int depth = Math.max(l_result[0], r_result[0]) + 1;
        int precision = l_result[1] + r_result[1] + (node.value.equals(".") ? 1 : 0);
        return new int[]{depth, precision};
    }

    static int[] evaluate_expression(String expression) {
        Node build_tree(java.util.List<String> tokens) {
            if (tokens.isEmpty()) {
                return null;
            }
            String token = tokens.remove(0);
            if (token.equals("(")) {
                Node node = new Node(token, null, null);
                node.left = build_tree(tokens);
                tokens.remove(0);
                node.right = build_tree(tokens);
                return node;
            } else {
                return new Node(token, null, null);
            }
        }

        java.util.List<String> tokens = new java.util.ArrayList<>();
        for (char char1 : expression.toCharArray()) {
            if (char1 == '(' || char1 == ')') {
                tokens.add(String.valueOf(char1));
            } else if (char1 == '.') {
                tokens.add(String.valueOf(char1));
            } else if (!tokens.isEmpty() && !tokens.get(tokens.size() - 1).equals("(") && !tokens.get(tokens.size() - 1).equals(")")) {
                tokens.set(tokens.size() - 1, tokens.get(tokens.size() - 1) + char1);
            } else {
                tokens.add(String.valueOf(char1));
            }
        }
        Node root = build_tree(tokens);
        return analyze_tree(root);
    }

    static void main(String[] args) {
        while (true) {
            String expression = "1.234+(5.678*(9.012/3.456))";
            int[] result = evaluate_expression(expression);
            System.out.println("Depth: " + result[0] + ", Precision: " + result[1]);
        }
    }
}