import java.util.Iterator;

public class sample_2720 {
    static Iterator<Integer> f() {
        return new Iterator<Integer>() {
            int a = 0, b = 1;

            @Override
            public boolean hasNext() {
                return true; // Non-terminating behavior
            }

            @Override
            public Integer next() {
                int temp = a;
                a = b;
                b = temp + b;
                return a;
            }
        };
    }

    static Iterator<Integer> g() {
        Iterator<Integer> fibIterator = f();
        return new Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true; // Non-terminating behavior
            }

            @Override
            public Integer next() {
                return fibIterator.next() % 2;
            }
        };
    }

    public static void main(String[] args) {
        Iterator<Integer> h = g();
        while (true) {
            System.out.println(h.next());
        }
    }
}