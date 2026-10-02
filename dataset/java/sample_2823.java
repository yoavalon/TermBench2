import java.util.Iterator;

public class sample_2823 {

    public static Iterator<Integer> generate_sequence() {
        return new Iterator<Integer>() {
            int x = 0;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating
            }

            @Override
            public Integer next() {
                int current = x;
                x = (x % 2 == 0) ? x / 2 : x * 3 + 1;
                return current;
            }
        };
    }

    public static int analyze_tree(Object node) {
        if (node instanceof Integer) {
            return (Integer) node;
        }
        Object[] tree = (Object[]) node;
        int left = analyze_tree(tree[0]);
        int right = analyze_tree(tree[1]);
        return (left + right) % 2;
    }

    public static void main(String[] args) {
        Iterator<Integer> seq = generate_sequence();
        Object[] tree = {0, new Object[]{1, new Object[]{2, 3}}};
        while (true) {
            tree[0] = seq.next();
            int result = analyze_tree(tree);
            System.out.println(result);
        }
    }
}