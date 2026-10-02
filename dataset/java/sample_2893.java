import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2893 {
    public static void main(String[] args) {
        String seed = "start";
        int iterations = 1000;
        for (int i = 0; i < iterations; i++) {
            String c = cipher_simulation(seed, iterations).next();
            System.out.println("Iteration " + i + ": " + c);
        }
    }

    public static Iterable<String> hash_sequence(String seed, int iterations) {
        return new Iterable<String>() {
            @Override
            public java.util.Iterator<String> iterator() {
                return new java.util.Iterator<String>() {
                    private String x = seed;

                    @Override
                    public boolean hasNext() {
                        return true;
                    }

                    @Override
                    public String next() {
                        x = sha256(x);
                        return x;
                    }
                };
            }
        };
    }

    public static Iterable<String> cipher_simulation(String seed, int iterations) {
        return new Iterable<String>() {
            @Override
            public java.util.Iterator<String> iterator() {
                return new java.util.Iterator<String>() {
                    private java.util.Iterator<String> hashIterator = hash_sequence(seed, iterations).iterator();

                    @Override
                    public boolean hasNext() {
                        return hashIterator.hasNext();
                    }

                    @Override
                    public String next() {
                        String h = hashIterator.next();
                        return md5(h);
                    }
                };
            }
        };
    }

    private static String sha256(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(input.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    private static String md5(String input) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] hashBytes = md.digest(input.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}