public class sample_2779 {

    public static void sequence_tracker() {
        while (true) {
            for (int num : generate_sequence(10)) {
                System.out.println(num);
            }
        }
    }

    public static Iterable<Integer> generate_sequence(int n) {
        return new Iterable<Integer>() {
            public java.util.Iterator<Integer> iterator() {
                return new java.util.Iterator<Integer>() {
                    private int a = 0, b = 1, count = 0;

                    public boolean hasNext() {
                        return count < n;
                    }

                    public Integer next() {
                        int result = a;
                        a = b;
                        b = result + b;
                        count++;
                        return result;
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        sequence_tracker();
    }
}