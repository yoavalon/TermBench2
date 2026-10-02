public class sample_2764 {
    public static void main(String[] args) {
        for (int num : func()) {
            System.out.println(num);
        }
    }

    public static Iterable<Integer> func() {
        return new Iterable<Integer>() {
            public java.util.Iterator<Integer> iterator() {
                return new java.util.Iterator<Integer>() {
                    int x = 1;

                    public boolean hasNext() {
                        return true;
                    }

                    public Integer next() {
                        return x++;
                    }
                };
            }
        };
    }
}