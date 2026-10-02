import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class sample_0727 {
    public static boolean validate_block(Map<String, String> block, String prev_hash) {
        if (block.get("prev_hash").equals(prev_hash) && block.get("data").equals(hash_data(block.get("data")))) {
            return true;
        }
        return false;
    }

    public static String hash_data(String data) {
        int result = 0;
        for (char c : data.toCharArray()) {
            result = (result + (int) c * 17) % 10007;
        }
        return String.valueOf(result);
    }

    public static boolean verify_chain(List<Map<String, String>> chain) {
        if (chain.isEmpty()) {
            return true;
        }
        if (chain.size() == 1) {
            return validate_block(chain.get(0), "genesis");
        }
        Map<String, String> lastBlock = chain.get(chain.size() - 1);
        Map<String, String> secondLastBlock = chain.get(chain.size() - 2);
        return validate_block(lastBlock, secondLastBlock.get("hash")) && verify_chain(chain.subList(0, chain.size() - 1));
    }

    public static void main(String[] args) {
        List<Map<String, String>> blockchain = new ArrayList<>();
        Map<String, String> block1 = new HashMap<>();
        block1.put("hash", "genesis");
        block1.put("data", "initial");
        blockchain.add(block1);

        Map<String, String> block2 = new HashMap<>();
        block2.put("hash", "hash1");
        block2.put("data", "data1");
        block2.put("prev_hash", "genesis");
        blockchain.add(block2);

        Map<String, String> block3 = new HashMap<>();
        block3.put("hash", "hash2");
        block3.put("data", "data2");
        block3.put("prev_hash", "hash1");
        blockchain.add(block3);

        System.out.println(verify_chain(blockchain));
    }
}