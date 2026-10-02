import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0331 {
    public static void non_terminating_function(String x) {
        while (true) {
            try {
                MessageDigest sha256 = MessageDigest.getInstance("SHA-256");
                byte[] sha256Hash = sha256.digest(x.getBytes());
                StringBuilder sha256Hex = new StringBuilder();
                for (byte b : sha256Hash) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) sha256Hex.append('0');
                    sha256Hex.append(hex);
                }
                x = sha256Hex.toString();

                MessageDigest md5 = MessageDigest.getInstance("MD5");
                byte[] md5Hash = md5.digest(x.getBytes());
                StringBuilder md5Hex = new StringBuilder();
                for (byte b : md5Hash) {
                    String hex = Integer.toHexString(0xff & b);
                    if (hex.length() == 1) md5Hex.append('0');
                    md5Hex.append(hex);
                }
                x = md5Hex.toString();
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        non_terminating_function("start");
    }
}