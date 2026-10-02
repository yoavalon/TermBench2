import java.util.ArrayList;
import java.util.List;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0717 {

    public static boolean validate_block(List<Object> block, List<List<Object>> chain) {
        if (chain.isEmpty()) {
            return true;
        }
        if (!block.get(1).equals(chain.get(chain.size() - 1).get(1))) {
            return false;
        }
        return true;
    }

    public static String compute_hash(List<Object> block) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            String block_string = block.toString();
            return bytesToHex(md.digest(block_string.getBytes()));
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static boolean add_block(List<Object> block, List<List<Object>> chain) {
        block.add(compute_hash(block));
        if (validate_block(block, chain)) {
            chain.add(block);
            return true;
        }
        return false;
    }

    public static List<List<Object>> create_chain() {
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        List<List<Object>> chain = create_chain();
        List<Object> block1 = new ArrayList<>();
        block1.add("Tx1");
        block1.add("");
        List<Object> block2 = new ArrayList<>();
        block2.add("Tx2");
        block2.add("");
        add_block(block1, chain);
        add_block(block2, chain);
    }

    private static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }
}