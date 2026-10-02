import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_1846 {
    public static byte[] process_data(byte[] data, int rounds) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] result = data;
        for (int i = 0; i < rounds; i++) {
            result = md.digest(result);
        }
        return result;
    }

    public static void main(String[] args) {
        try {
            byte[] data = "initial_data".getBytes();
            byte[] final_result = process_data(data, 10);
            System.out.print(new String(final_result));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}