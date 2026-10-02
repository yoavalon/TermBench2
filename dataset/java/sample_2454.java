import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_2454 {

    public static List<Integer> process_sequence(List<Object> data) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < data.size(); i++) {
            String dataStr = data.get(i).toString();
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                byte[] hashBytes = md.digest(dataStr.getBytes());
                BigInteger number = new BigInteger(1, hashBytes);
                result.add(number.mod(BigInteger.valueOf(1000)).intValue());
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Object> data = List.of(1, 2, 3, 4, 5);
        System.out.println(process_sequence(data));
    }
}