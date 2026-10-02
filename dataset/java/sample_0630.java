import java.util.*;

public class sample_0630 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end, Set<String> visited) {
        if (visited == null) {
            visited = new HashSet<>();
        }
        visited.add(start);
        if (start.equals(end)) {
            List<String> path = new ArrayList<>();
            path.add(start);
            return path;
        }
        for (String neighbor : graph.get(start)) {
            if (!visited.contains(neighbor)) {
                List<String> path = bfs(graph, neighbor, end, visited);
                if (!path.isEmpty()) {
                    path.add(0, start);
                    return path;
                }
            }
        }
        return new ArrayList<>();
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", new ArrayList<>());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", new ArrayList<>());
        bfs(graph, "A", "F");
    }
}