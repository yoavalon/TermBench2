import java.util.*;

public class sample_2451 {
    public static List<String> find_shortest_path(Map<String, Set<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, new ArrayList<>(Collections.singletonList(start))));
        while (!queue.isEmpty()) {
            Pair<String, List<String>> pair = queue.poll();
            String vertex = pair.getKey();
            List<String> path = pair.getValue();
            for (String next_vertex : graph.get(vertex)) {
                if (!path.contains(next_vertex)) {
                    if (next_vertex.equals(end)) {
                        path.add(next_vertex);
                        return path;
                    } else {
                        List<String> new_path = new ArrayList<>(path);
                        new_path.add(next_vertex);
                        queue.add(new Pair<>(next_vertex, new_path));
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, Set<String>> graph = new HashMap<>();
        graph.put("A", new HashSet<>(Arrays.asList("B", "C")));
        graph.put("B", new HashSet<>(Arrays.asList("A", "D", "E")));
        graph.put("C", new HashSet<>(Arrays.asList("A", "F")));
        graph.put("D", new HashSet<>(Arrays.asList("B")));
        graph.put("E", new HashSet<>(Arrays.asList("B", "F")));
        graph.put("F", new HashSet<>(Arrays.asList("C", "E")));
        String start = "A";
        String end = "F";
        System.out.println(find_shortest_path(graph, start, end));
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