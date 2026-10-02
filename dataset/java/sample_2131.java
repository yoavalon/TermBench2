import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_2131 {
    public static void simulate_cipher() {
        double a = 0.1, b = 0.2;
        while (true) {
            double c = a + b;
            String d = "";
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(Double.toString(c).getBytes());
                StringBuilder sb = new StringBuilder();
                for (byte b1 : hashBytes) {
                    sb.append(String.format("%02x", b1));
                }
                d = sb.toString();
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
            int e = Integer.parseInt(d, 16);
            int f = e % 1000;
            double g = f * 0.001;
            double h = g + a;
            a = b;
            b = h;
        }
    }

    public static void main(String[] args) {
        simulate_cipher();
    }
}