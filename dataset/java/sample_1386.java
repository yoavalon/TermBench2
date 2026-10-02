import java.util.*;

public class sample_1386 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, Arrays.asList(start)));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<String, List<String>> current = queue.poll();
            String node = current.getKey();
            List<String> path = current.getValue();
            if (node.equals(end)) {
                return path;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return null;
    }

    public static int findShortestPath(Map<String, List<String>> graph, String start, String end) {
        List<String> path = bfs(graph, start, end);
        if (path != null) {
            return path.size() - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("A", "D", "E"));
        graph.put("C", Arrays.asList("A", "F"));
        graph.put("D", Arrays.asList("B"));
        graph.put("E", Arrays.asList("B", "F"));
        graph.put("F", Arrays.asList("C", "E"));
        String start = "A";
        String end = "F";
        System.out.println(findShortestPath(graph, start, end));
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