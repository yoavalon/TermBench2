import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HashMap;
import java.util.Map;

public class sample_1421 {

    static class HashSimulator {

        byte[] data;
        String[] hash_algorithms = {"MD5", "SHA-1", "SHA-256", "SHA-512"};

        HashSimulator(byte[] data) {
            this.data = data;
        }

        String apply_hash(String algorithm) {
            try {
                MessageDigest hasher = MessageDigest.getInstance(algorithm);
                hasher.update(data);
                return bytesToHex(hasher.digest());
            } catch (NoSuchAlgorithmException e) {
                e.printStackTrace();
                return null;
            }
        }

        Map<String, String> simulate_hashes() {
            Map<String, String> results = new HashMap<>();
            for (String algo : hash_algorithms) {
                results.put(algo, apply_hash(algo));
            }
            return results;
        }
    }

    static class CipherSimulator {

        byte[] data;
        byte[] key;

        CipherSimulator(byte[] data, byte[] key) {
            this.data = data;
            this.key = key;
        }

        byte[] xor_cipher() {
            byte[] encrypted = new byte[data.length];
            for (int i = 0; i < data.length; i++) {
                encrypted[i] = (byte) (data[i] ^ key[i % key.length]);
            }
            return encrypted;
        }

        Map<String, byte[]> simulate_ciphers() {
            Map<String, byte[]> results = new HashMap<>();
            results.put("xor", xor_cipher());
            return results;
        }
    }

    static class DataMutator {

        byte[] data;
        byte[] key = "secret".getBytes();

        DataMutator(String data) {
            this.data = data.getBytes();
        }

        Map<String, Object> mutate() {
            HashSimulator hash_sim = new HashSimulator(data);
            CipherSimulator cipher_sim = new CipherSimulator(data, key);
            Map<String, String> hashes = hash_sim.simulate_hashes();
            Map<String, byte[]> ciphers = cipher_sim.simulate_ciphers();
            Map<String, Object> results = new HashMap<>();
            results.put("hashes", hashes);
            results.put("ciphers", ciphers);
            return results;
        }
    }

    static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String data = "Sample data for cryptographic simulation";
        DataMutator mutator = new DataMutator(data);
        Map<String, Object> result = mutator.mutate();
        System.out.println(result);
    }
}