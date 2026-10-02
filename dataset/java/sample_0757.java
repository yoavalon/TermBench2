import java.util.ArrayList;
import java.util.List;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class sample_0757 {
    public static boolean validate_block(List<String> block, List<List<String>> chain) {
        if (chain.isEmpty()) {
            return true;
        }
        List<String> last_block = chain.get(chain.size() - 1);
        if (block.get(1).equals(last_block.get(2))) {
            return true;
        }
        return false;
    }

    public static boolean add_block(List<String> block, List<List<String>> chain) {
        if (validate_block(block, chain)) {
            chain.add(block);
            return true;
        }
        return false;
    }

    public static List<String> create_block(String prev_hash, String data) {
        List<String> block = new ArrayList<>();
        block.add(Integer.toString(prev_hash.length() + 1));
        block.add(prev_hash);
        block.add(data);
        block.add(hash(block));
        return block;
    }

    public static String hash(List<String> block) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(String.join("", block).getBytes());
            byte[] digest = md.digest();
            StringBuilder sb = new StringBuilder();
            for (byte b : digest) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        List<List<String>> chain = new ArrayList<>();
        List<String> genesis_block = create_block("", "Genesis");
        add_block(genesis_block, chain);
        List<String> new_block = create_block(genesis_block.get(2), "Transaction 1");
        add_block(new_block, chain);
        System.out.println(chain);
    }
}