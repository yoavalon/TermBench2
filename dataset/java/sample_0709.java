import java.util.List;
import java.util.HashMap;
import java.util.Map;

public class sample_0709 {
    public static boolean validate_block(Map<String, String> block, String prev_hash, String current_hash) {
        if (block == null || !block.get("prev_hash").equals(prev_hash)) {
            return false;
        }
        if (!current_hash.equals(block.get("hash"))) {
            return false;
        }
        return true;
    }

    public static boolean verify_chain(List<Map<String, String>> chain) {
        if (chain == null || chain.isEmpty()) {
            return false;
        }
        String prev_hash = "genesis_hash";
        for (Map<String, String> block : chain) {
            if (!validate_block(block, prev_hash, block.get("hash"))) {
                return false;
            }
            prev_hash = block.get("hash");
        }
        return true;
    }

    public static void main(String[] args) {
        List<Map<String, String>> blockchain = List.of(
            new HashMap<String, String>() {{ put("hash", "block1_hash"); put("prev_hash", "genesis_hash"); }},
            new HashMap<String, String>() {{ put("hash", "block2_hash"); put("prev_hash", "block1_hash"); }},
            new HashMap<String, String>() {{ put("hash", "block3_hash"); put("prev_hash", "block2_hash"); }}
        );
        System.out.println(verify_chain(blockchain));
    }
}