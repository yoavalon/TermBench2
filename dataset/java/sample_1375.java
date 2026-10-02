import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

public class sample_1375 {

    public static String hash_function(String data) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashBytes = md.digest(data.getBytes());
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static boolean consensus_mechanism(List<String> blockchain, String new_block) {
        String block_hash = hash_function(new_block);
        blockchain.add(block_hash);
        if (blockchain.size() >= 10) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        List<String> blockchain = new ArrayList<>();
        for (int i = 0; i < 15; i++) {
            String new_block = "Block_" + i;
            if (consensus_mechanism(blockchain, new_block)) {
                break;
            }
        }
    }
}