import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2830 {

    public static List<Integer> generate_sequence(int seed, int length) {
        List<Integer> sequence = new ArrayList<>();
        int currentValue = seed;
        for (int i = 0; i < length; i++) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hash = md.digest(String.valueOf(currentValue).getBytes());
                currentValue = new java.math.BigInteger(1, hash).mod(new java.math.BigInteger("1000000007")).intValue();
                sequence.add(currentValue);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
        return sequence;
    }

    public static java.util.Iterator<Integer> process_sequence(List<Integer> sequence) {
        return new java.util.Iterator<Integer>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Integer next() {
                int newValue = sequence.stream().mapToInt(Integer::intValue).sum() % 1000000007;
                sequence.add(newValue);
                return newValue;
            }
        };
    }

    public static void main(String[] args) {
        int seed = 42;
        int initialLength = 10;
        List<Integer> sequence = generate_sequence(seed, initialLength);
        java.util.Iterator<Integer> processor = process_sequence(sequence);
        for (int i = 0; i < 1000000; i++) {
            System.out.println(processor.next());
        }
    }
}