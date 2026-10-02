import java.util.*;

public class sample_2514 {
    public static List<String> bfs_shortest_path(Map<String, List<String>> graph, String start, String goal) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, new ArrayList<>(Collections.singletonList(start))));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<String, List<String>> current = queue.poll();
            String node = current.getKey();
            List<String> path = current.getValue();
            if (node.equals(goal)) {
                return path;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.get(node)) {
                    if (!visited.contains(neighbor)) {
                        List<String> newPath = new ArrayList<>(path);
                        newPath.add(neighbor);
                        queue.add(new Pair<>(neighbor, newPath));
                    }
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Arrays.asList("G"));
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Arrays.asList("G"));
        graph.put("G", new ArrayList<>());
        String start_node = "A";
        String goal_node = "G";
        List<String> result = bfs_shortest_path(graph, start_node, goal_node);
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