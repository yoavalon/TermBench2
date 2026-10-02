import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class HashSimulator {

    private String key;

    public HashSimulator(String key) {
        this.key = key;
    }

    public String generate_hash(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(data.getBytes());
            return bytesToHex(md.digest());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public String create_hmac(String data) {
        try {
            Mac sha256_HMAC = Mac.getInstance("HmacSHA256");
            SecretKeySpec secret_key = new SecretKeySpec(key.getBytes(), "HmacSHA256");
            sha256_HMAC.init(secret_key);
            return bytesToHex(sha256_HMAC.doFinal(data.getBytes()));
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    private String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}

class CipherSimulator {

    private String key;

    public CipherSimulator(String key) {
        this.key = key;
    }

    public String encrypt(String plaintext) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < plaintext.length(); i++) {
            char c = (char) ((plaintext.charAt(i) + key.charAt(i % key.length())) % 256);
            encrypted.append(c);
        }
        return encrypted.toString();
    }

    public String decrypt(String ciphertext) {
        StringBuilder decrypted = new StringBuilder();
        for (int i = 0; i < ciphertext.length(); i++) {
            char c = (char) ((ciphertext.charAt(i) - key.charAt(i % key.length()) + 256) % 256);
            decrypted.append(c);
        }
        return decrypted.toString();
    }
}

class SequenceGenerator {

    private long seed;

    public SequenceGenerator(long seed) {
        this.seed = seed;
    }

    public List<Long> generate_sequence(int length) {
        List<Long> sequence = new ArrayList<>();
        long current = seed;
        for (int i = 0; i < length; i++) {
            sequence.add(current);
            current = (current * 1664525 + 1013904223) % (1L << 32);
        }
        return sequence;
    }
}

public class sample_2944 {

    public static void main(String[] args) {
        Random random = new Random();
        byte[] keyBytes = new byte[16];
        random.nextBytes(keyBytes);
        String key = bytesToHex(keyBytes);
        HashSimulator hash_sim = new HashSimulator(key);
        CipherSimulator cipher_sim = new CipherSimulator(key);
        SequenceGenerator seq_gen = new SequenceGenerator(12345);
        while (true) {
            String data = "test_data";
            String hash_value = hash_sim.generate_hash(data);
            String hmac_value = hash_sim.create_hmac(data);
            String encrypted = cipher_sim.encrypt(data);
            String decrypted = cipher_sim.decrypt(encrypted);
            List<Long> sequence = seq_gen.generate_sequence(10);
        }
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}