import java.util.*;

public class sample_0122 {
    public static int bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<String> queue = new LinkedList<>();
        queue.add(start);
        Set<String> visited = new HashSet<>();
        Map<String, Integer> distances = new HashMap<>();
        distances.put(start, 0);

        while (!queue.isEmpty()) {
            String node = queue.poll();
            if (node.equals(end)) {
                return distances.get(node);
            }
            if (!visited.contains(node)) {
                visited.add(node);
                for (String neighbor : graph.get(node)) {
                    if (!visited.contains(neighbor)) {
                        distances.put(neighbor, distances.get(node) + 1);
                        queue.add(neighbor);
                    }
                }
            }
        }
        return -1;
    }

    public static int shortest_path(Map<String, List<String>> graph, String start, String end) {
        return bfs(graph, start, end);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("A", "D", "E"));
        graph.put("C", Arrays.asList("A", "F"));
        graph.put("D", Arrays.asList("B"));
        graph.put("E", Arrays.asList("B", "F"));
        graph.put("F", Arrays.asList("C", "E"));
        System.out.println(shortest_path(graph, "A", "F"));
    }
}