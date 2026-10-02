import java.util.*;

public class sample_0798 {
    public static List<String> dfs(Map<String, List<String>> graph, String node, Set<String> visited, List<String> path) {
        visited.add(node);
        path.add(node);
        if (path.size() == graph.size()) {
            return path;
        }
        for (String neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                List<String> result = dfs(graph, neighbor, new HashSet<>(visited), new ArrayList<>(path));
                if (result != null) {
                    return result;
                }
            }
        }
        return null;
    }

    public static List<String> shortest_path(Map<String, List<String>> graph, String start) {
        Set<String> visited = new HashSet<>();
        List<String> path = dfs(graph, start, visited, new ArrayList<>());
        return path != null ? path : new ArrayList<>();
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
        System.out.println(shortest_path(graph, start));
    }
}