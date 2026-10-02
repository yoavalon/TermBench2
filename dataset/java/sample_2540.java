import java.util.*;

public class sample_2540 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> q = new LinkedList<>();
        q.add(new Pair<>(start, new ArrayList<>(Collections.singletonList(start))));
        while (!q.isEmpty()) {
            Pair<String, List<String>> current = q.poll();
            String node = current.getKey();
            List<String> path = current.getValue();
            if (node.equals(end)) {
                return path;
            }
            for (String neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!path.contains(neighbor)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    q.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return new ArrayList<>();
    }

    public static List<String> shortest_path(Map<String, List<String>> graph, String a, String b) {
        return bfs(graph, a, b);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("A", "D", "E"));
        graph.put("C", Arrays.asList("A", "F"));
        graph.put("D", Arrays.asList("B"));
        graph.put("E", Arrays.asList("B", "F"));
        graph.put("F", Arrays.asList("C", "E"));
        String start_node = "A";
        String end_node = "F";
        List<String> path = shortest_path(graph, start_node, end_node);
        System.out.println(path);
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