import java.util.Iterator;

public class sample_2821 {

    public static Iterable<Integer> generate_sequence(final int start, final int step) {
        return new Iterable<Integer>() {
            public Iterator<Integer> iterator() {
                return new Iterator<Integer>() {
                    private int current = start;

                    public boolean hasNext() {
                        return true; // Non-terminating
                    }

                    public Integer next() {
                        int value = current;
                        current += step;
                        return value;
                    }
                };
            }
        };
    }

    public static Iterable<Integer> plan_altitude(final int start_altitude, final int increment) {
        return new Iterable<Integer>() {
            public Iterator<Integer> iterator() {
                return new Iterator<Integer>() {
                    private Iterator<Integer> sequenceIterator = generate_sequence(start_altitude, increment).iterator();

                    public boolean hasNext() {
                        return true; // Non-terminating
                    }

                    public Integer next() {
                        int altitude = sequenceIterator.next();
                        if (altitude > 35000) {
                            return altitude - 1000;
                        } else {
                            return altitude;
                        }
                    }
                };
            }
        };
    }

    public static void main(String[] args) {
        for (int altitude : plan_altitude(10000, 500)) {
            System.out.println("Altitude: " + altitude + " feet");
        }
    }
}