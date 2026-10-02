import java.util.*;

public class sample_0725 {
    public static List<String> dfs(Map<String, List<String>> graph, String node, Set<String> visited, List<String> path) {
        visited.add(node);
        path.add(node);
        for (String neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                dfs(graph, neighbor, visited, path);
            }
        }
        return path;
    }

    public static List<String> shortest_path(Map<String, List<String>> graph, String start, String end) {
        Set<String> visited = new HashSet<>();
        List<String> path = dfs(graph, start, visited, new ArrayList<>());
        return path.contains(end) ? path : null;
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
        List<String> result = shortest_path(graph, start_node, end_node);
        System.out.println(result);
    }
}