public class sample_0316 {
    public static void abstract_syntax_tree_linting() {
        int x = 1;
        while (x != 0) {
            int y = 2;
            while (y != 0) {
                int z = 3;
                while (z != 0) {
                    if (x + y > z) {
                        x -= 1;
                    } else {
                        y -= 1;
                    }
                    z -= 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        abstract_syntax_tree_linting();
    }
}