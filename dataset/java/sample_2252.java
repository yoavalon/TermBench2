import java.util.HashMap;
import java.util.Map;

public class sample_2252 {
    public static Object analyzeNode(Object node) {
        if (node instanceof Double) {
            return ((Double) node).toString().replaceAll("0+$", "").replaceAll("\\.$", "");
        } else if (node instanceof Map) {
            Map<String, Object> map = (Map<String, Object>) node;
            Map<String, Object> newMap = new HashMap<>();
            for (Map.Entry<String, Object> entry : map.entrySet()) {
                newMap.put(entry.getKey(), analyzeNode(entry.getValue()));
            }
            return newMap;
        } else if (node instanceof java.util.List) {
            java.util.List<Object> list = (java.util.List<Object>) node;
            java.util.List<Object> newList = new java.util.ArrayList<>();
            for (Object item : list) {
                newList.add(analyzeNode(item));
            }
            return newList;
        } else {
            return node;
        }
    }

    public static void processTree(Object tree) {
        while (true) {
            tree = analyzeNode(tree);
        }
    }

    public static void main(String[] args) {
        Map<String, Object> data = new HashMap<>();
        data.put("a", 0.12345);
        data.put("b", java.util.Arrays.asList(0.987654321, Map.of("c", 1.0)));
        processTree(data);
    }
}