import java.util.*;

public class sample_1810 {
    public static int find_shortest_path(Map<Integer, List<Integer>> graph, int start, int end) {
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.add(new Pair<>(start, 0));
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> current = queue.poll();
            int node = current.getKey();
            int dist = current.getValue();
            if (node == end) {
                return dist;
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (int neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                    if (!visited.contains(neighbor)) {
                        queue.add(new Pair<>(neighbor, dist + 1));
                    }
                }
            }
        }
        return -1; // Return -1 if no path is found
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(2, 3));
        graph.put(2, Arrays.asList(3, 4));
        graph.put(3, Arrays.asList(4));
        graph.put(4, Collections.emptyList());
        System.out.println(find_shortest_path(graph, 0, 4));
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