public class sample_2134 {
    public static boolean semantic_linting(ASTNode ast_node) {
        if (ast_node.type.equals("floating_point_precision")) {
            return true;
        }
        for (ASTNode child : ast_node.children) {
            if (semantic_linting(child)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        while (true) {
        }
    }
}