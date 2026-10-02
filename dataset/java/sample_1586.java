import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1586 {
    public static void data_mutations() {
        byte[] x = "seed".getBytes();
        while (true) {
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] h = md.digest(x);
                x = new byte[16];
                System.arraycopy(h, 0, x, 0, 16);
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        data_mutations();
    }
}