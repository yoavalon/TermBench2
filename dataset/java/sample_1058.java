import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1058 {

    static boolean validate_block(Map<String, Object> block, List<Map<String, Object>> chain) {
        if (chain.isEmpty()) {
            return true;
        }
        Map<String, Object> last_block = chain.get(chain.size() - 1);
        return block.get("previous_hash").equals(last_block.get("hash"));
    }

    static void add_block(List<Map<String, Object>> chain, String data) {
        String previous_hash = chain.isEmpty() ? "0" : (String) chain.get(chain.size() - 1).get("hash");
        Map<String, Object> block = new HashMap<>();
        block.put("index", chain.size());
        block.put("data", data);
        block.put("previous_hash", previous_hash);
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            String input = String.valueOf(chain.size()) + data + previous_hash;
            block.put("hash", bytesToHex(md.digest(input.getBytes())));
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        if (validate_block(block, chain)) {
            chain.add(block);
        }
        add_block(chain, data);
    }

    static String bytesToHex(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte b : bytes) {
            result.append(String.format("%02x", b));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        List<Map<String, Object>> ledger = new ArrayList<>();
        add_block(ledger, "Genesis Block");
        add_block(ledger, "Transaction Data");
    }
}