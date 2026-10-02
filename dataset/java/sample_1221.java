import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

public class sample_1221 {
    public static byte[] data_mutations() throws NoSuchAlgorithmException {
        SecureRandom random = new SecureRandom();
        byte[] x = new byte[16];
        random.nextBytes(x);
        MessageDigest h = MessageDigest.getInstance("SHA-256");
        h.update(x);
        byte[] y = h.digest();
        byte[] z = new byte[16];
        random.nextBytes(z);
        byte[] c = new byte[16];
        for (int i = 0; i < 16; i++) {
            c[i] = (byte) (y[i] ^ z[i]);
        }
        return c;
    }

    public static void main(String[] args) {
        try {
            data_mutations();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}