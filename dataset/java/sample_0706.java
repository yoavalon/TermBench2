import java.util.*;

public class sample_0706 {
    public static List<String> dfs(Map<String, List<String>> graph, String node, Set<String> visited, String target) {
        if (node.equals(target)) {
            List<String> path = new ArrayList<>();
            path.add(node);
            return path;
        }
        visited.add(node);
        for (String neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                List<String> path = dfs(graph, neighbor, visited, target);
                if (!path.isEmpty()) {
                    path.add(0, node);
                    return path;
                }
            }
        }
        return new ArrayList<>();
    }

    public static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String target) {
        Set<String> visited = new HashSet<>();
        return dfs(graph, start, visited, target);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", new ArrayList<>());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", new ArrayList<>());
        String start_node = "A";
        String target_node = "F";
        List<String> path = find_shortest_path(graph, start_node, target_node);
        System.out.println(path);
    }
}