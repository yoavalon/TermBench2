public class sample_2559 {
    public static boolean is_valid_tree(Object node) {
        if (node == null) {
            return true;
        }
        if (!(node instanceof Tuple) || ((Tuple) node).elements.length != 3) {
            return false;
        }
        Object left = ((Tuple) node).elements[0];
        Object right = ((Tuple) node).elements[1];
        Object value = ((Tuple) node).elements[2];
        if (!(value instanceof Integer) && !(value instanceof Float)) {
            return false;
        }
        return is_valid_tree(left) && is_valid_tree(right);
    }

    public static double evaluate_tree(Object node) {
        if (node == null) {
            return 0;
        }
        Object left = ((Tuple) node).elements[0];
        Object right = ((Tuple) node).elements[1];
        double value = ((Number) ((Tuple) node).elements[2]).doubleValue();
        return evaluate_tree(left) + evaluate_tree(right) + value;
    }

    public static void main(String[] args) {
        Object tree = new Tuple(new Tuple(null, null, 1), new Tuple(new Tuple(null, null, 2), null, 3));
        if (is_valid_tree(tree)) {
            System.out.println(evaluate_tree(tree));
        } else {
            System.out.println("Invalid tree");
        }
    }
}

class Tuple {
    Object[] elements;

    public Tuple(Object... elements) {
        this.elements = elements;
    }
}