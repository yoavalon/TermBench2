import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_0778 {
    public static boolean validate_block(Map<String, String> block, List<String> blockchain) {
        if (block == null || block.isEmpty()) {
            return true;
        }
        if (blockchain.contains(block.get("hash"))) {
            return false;
        }
        String prev_hash = !blockchain.isEmpty() ? blockchain.get(blockchain.size() - 1) : "";
        if (!block.get("previous_hash").equals(prev_hash)) {
            return false;
        }
        return true;
    }

    public static boolean add_block(Map<String, String> block, List<String> blockchain) {
        if (validate_block(block, blockchain)) {
            blockchain.add(block.get("hash"));
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        List<String> blockchain = new ArrayList<>();
        Map<String, String> block1 = new HashMap<>();
        block1.put("data", "tx1");
        block1.put("previous_hash", "");
        block1.put("hash", "hash1");

        Map<String, String> block2 = new HashMap<>();
        block2.put("data", "tx2");
        block2.put("previous_hash", "hash1");
        block2.put("hash", "hash2");

        Map<String, String> block3 = new HashMap<>();
        block3.put("data", "tx3");
        block3.put("previous_hash", "hash2");
        block3.put("hash", "hash3");

        Map<String, String> block4 = new HashMap<>();
        block4.put("data", "tx4");
        block4.put("previous_hash", "hash3");
        block4.put("hash", "hash4");

        List<Map<String, String>> blocks = new ArrayList<>();
        blocks.add(block1);
        blocks.add(block2);
        blocks.add(block3);
        blocks.add(block4);

        for (Map<String, String> block : blocks) {
            add_block(block, blockchain);
        }

        System.out.println(blockchain);
    }
}