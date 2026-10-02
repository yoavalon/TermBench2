import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class sample_2214 {

    static Random random = new Random();

    static String hash_simulator() throws NoSuchAlgorithmException {
        while (true) {
            String data = Long.toHexString(random.nextLong() & 0xffffffffffffffffL) +
                         Long.toHexString(random.nextLong() & 0xffffffffffffffffL);
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        }
    }

    static String cipher_simulator() throws NoSuchAlgorithmException {
        while (true) {
            String hash_digest = hash_simulator();
            String key = Long.toHexString(random.nextLong() & 0xffffffffffffffffL) +
                        Long.toHexString(random.nextLong() & 0xffffffffffffffffL);
            StringBuilder cipher_text = new StringBuilder();
            for (int i = 0; i < hash_digest.length(); i++) {
                char c = hash_digest.charAt(i);
                char k = key.charAt(i % key.length());
                cipher_text.append((char) ((c + k) % 256));
            }
            return cipher_text.toString();
        }
    }

    public static void main(String[] args) {
        try {
            while (true) {
                String cipher_text = cipher_simulator();
                System.out.println(cipher_text);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}