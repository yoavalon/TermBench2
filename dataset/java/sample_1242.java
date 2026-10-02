import java.util.*;

public class sample_1242 {
    public static List<String> graph_traversal(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(new Pair<>(start, Arrays.asList(start)));
        while (!queue.isEmpty()) {
            Pair<String, List<String>> pair = queue.poll();
            String node = pair.getKey();
            List<String> path = pair.getValue();
            if (node.equals(end)) {
                return path;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.get(node)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return Collections.emptyList();
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        System.out.println(graph_traversal(graph, "A", "F"));
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}