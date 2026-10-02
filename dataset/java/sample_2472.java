import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2472 {
    public static List<String> generate_hash_sequence(int n) throws NoSuchAlgorithmException {
        String data = "initial_data";
        List<String> hashes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            data = sb.toString();
            hashes.add(data);
        }
        return hashes;
    }

    public static void main(String[] args) {
        try {
            List<String> result = generate_hash_sequence(10);
            for (String item : result) {
                System.out.println(item);
            }
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }
}