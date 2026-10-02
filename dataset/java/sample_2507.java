import java.util.*;

public class sample_2507 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, Arrays.asList(start)));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<String, List<String>> current = queue.poll();
            String node = current.getKey();
            List<String> path = current.getValue();
            visited.add(node);
            if (node.equals(end)) {
                return path;
            }
            for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                if (!visited.contains(neighbor)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return Collections.emptyList();
    }

    public static List<String> shortest_path(Map<String, List<String>> graph, String start, String end) {
        return bfs(graph, start, end);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        String start_node = "A";
        String end_node = "F";
        List<String> result = shortest_path(graph, start_node, end_node);
        System.out.println(result);
    }
}

class Pair<K, V> {
    private K key;
    private V value;

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