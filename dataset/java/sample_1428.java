import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;

class HashSimulator {

    private String data;
    private String key;

    public HashSimulator(String data, String key) {
        this.data = data;
        this.key = key;
    }

    public String hash_data() {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hash = md.digest(data.getBytes());
            return Base64.getEncoder().encodeToString(hash);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public String hmac_data() {
        try {
            SecretKeySpec secretKeySpec = new SecretKeySpec(key.getBytes(), "HmacSHA256");
            Mac mac = Mac.getInstance("HmacSHA256");
            mac.init(secretKeySpec);
            byte[] hmac = mac.doFinal(data.getBytes());
            return Base64.getEncoder().encodeToString(hmac);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}

class CipherSimulator {

    private String data;
    private String key;

    public CipherSimulator(String data, String key) {
        this.data = data;
        this.key = key;
    }

    public String encrypt() {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char c = data.charAt(i);
            char k = key.charAt(i % key.length());
            encrypted.append((char) ((c + k) % 256));
        }
        return encrypted.toString();
    }

    public String decrypt(String encrypted_data) {
        StringBuilder decrypted = new StringBuilder();
        for (int i = 0; i < encrypted_data.length(); i++) {
            char c = encrypted_data.charAt(i);
            char k = key.charAt(i % key.length());
            decrypted.append((char) ((c - k + 256) % 256));
        }
        return decrypted.toString();
    }
}

public class sample_1428 {

    public static void main(String[] args) {
        String data = "SecureData";
        String key = "SecretKey";
        HashSimulator hash_sim = new HashSimulator(data, key);
        CipherSimulator cipher_sim = new CipherSimulator(data, key);
        String hash_result = hash_sim.hash_data();
        String hmac_result = hash_sim.hmac_data();
        String encrypted_data = cipher_sim.encrypt();
        System.out.println("Hash: " + hash_result);
        System.out.println("HMAC: " + hmac_result);
        System.out.println("Encrypted: " + encrypted_data);
        String decrypted_data = cipher_sim.decrypt(encrypted_data);
        System.out.println("Decrypted: " + decrypted_data);
    }
}