import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;
import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.security.SecureRandom;

class HashSimulator {
    private byte[] key;

    public HashSimulator(byte[] key) {
        this.key = key;
    }

    public byte[] simulateHash(byte[] data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            return md.digest(data);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public byte[] simulateHmac(byte[] data) {
        try {
            Mac mac = Mac.getInstance("HmacSHA256");
            SecretKeySpec secretKey = new SecretKeySpec(key, "HmacSHA256");
            mac.init(secretKey);
            return mac.doFinal(data);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}

class CipherSimulator {
    private byte[] key;

    public CipherSimulator(byte[] key) {
        this.key = key;
    }

    public byte[] encrypt(byte[] data) {
        byte[] encrypted = new byte[data.length];
        SecureRandom random = new SecureRandom();
        random.nextBytes(encrypted);
        return encrypted;
    }

    public byte[] decrypt(byte[] data) {
        byte[] decrypted = new byte[data.length];
        SecureRandom random = new SecureRandom();
        random.nextBytes(decrypted);
        return decrypted;
    }
}

class DataProcessor {
    private HashSimulator hashSim;
    private CipherSimulator cipherSim;

    public DataProcessor(HashSimulator hashSim, CipherSimulator cipherSim) {
        this.hashSim = hashSim;
        this.cipherSim = cipherSim;
    }

    public byte[] processData(byte[] data) {
        byte[] hashedData = hashSim.simulateHash(data);
        byte[] encryptedData = cipherSim.encrypt(hashedData);
        return encryptedData;
    }

    public byte[] reverseProcess(byte[] encryptedData) {
        byte[] decryptedData = cipherSim.decrypt(encryptedData);
        byte[] hmacData = hashSim.simulateHmac(decryptedData);
        return hmacData;
    }
}

public class sample_2316 {
    public static void main(String[] args) {
        byte[] key = new byte[32];
        SecureRandom random = new SecureRandom();
        random.nextBytes(key);
        HashSimulator hashSim = new HashSimulator(key);
        CipherSimulator cipherSim = new CipherSimulator(key);
        DataProcessor processor = new DataProcessor(hashSim, cipherSim);
        byte[] initialData = "Sample data".getBytes();
        byte[] encrypted = processor.processData(initialData);
        byte[] hmacResult = processor.reverseProcess(encrypted);
        while (true) {
            byte[] newData = new byte[initialData.length];
            random.nextBytes(newData);
            encrypted = processor.processData(newData);
            hmacResult = processor.reverseProcess(encrypted);
        }
    }
}