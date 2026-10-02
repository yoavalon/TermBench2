import java.util.*;

public class sample_2522 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String goal) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, Collections.singletonList(start)));
        while (!queue.isEmpty()) {
            Pair<String, List<String>> pair = queue.poll();
            String vertex = pair.getKey();
            List<String> path = pair.getValue();
            for (String next : new HashSet<>(graph.get(vertex)).removeAll(path)) {
                if (next.equals(goal)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(next);
                    return newPath;
                } else {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(next);
                    queue.add(new Pair<>(next, newPath));
                }
            }
        }
        return null;
    }

    public static List<String> findPath(Map<String, List<String>> graph, String start, String goal) {
        List<String> path = bfs(graph, start, goal);
        return path != null ? path : Collections.emptyList();
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        String startNode = "A";
        String goalNode = "F";
        List<String> result = findPath(graph, startNode, goalNode);
        System.out.println(result);
    }

    static class Pair<K, V> {
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
}