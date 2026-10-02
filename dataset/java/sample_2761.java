import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2761 {
    public static void main(String[] args) {
        for (String hashValue : hashCipherSimulation()) {
            System.out.println(hashValue);
        }
    }

    public static Iterable<String> hashCipherSimulation() {
        return () -> new java.util.Iterator<String>() {
            private String data = "";

            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public String next() {
                try {
                    MessageDigest md = MessageDigest.getInstance("SHA-256");
                    byte[] hashBytes = md.digest(String.valueOf(hashCipherSimulation.hashCode()).getBytes());
                    StringBuilder sb = new StringBuilder();
                    for (byte b : hashBytes) {
                        sb.append(String.format("%02x", b));
                    }
                    data = sb.toString();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                }
                return data;
            }
        };
    }
}