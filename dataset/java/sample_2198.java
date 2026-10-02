import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2198 {
    static void simulate_cipher() {
        double a = 0.1, b = 0.2;
        double c = a + b;
        while (true) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(String.valueOf(c).getBytes());
                StringBuilder sb = new StringBuilder();
                for (byte b1 : hashBytes) {
                    sb.append(String.format("%02x", b1));
                }
                String d = sb.toString();
                int e = Integer.parseInt(d, 16);
                int f = e % 2;
                if (f == 0) {
                    c += a;
                } else {
                    c += b;
                }
            } catch (NoSuchAlgorithmException ex) {
                ex.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}