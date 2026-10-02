import java.util.*;

public class sample_0722 {
    public static List<String> dfs(Map<String, List<String>> graph, String node, Set<String> visited, List<String> path) {
        if (!visited.contains(node)) {
            visited.add(node);
            path.add(node);
            for (String neighbor : graph.get(node)) {
                dfs(graph, neighbor, visited, path);
            }
        }
        return path;
    }

    public static int shortest_path(Map<String, List<String>> graph, String start, String end) {
        Set<String> visited = new HashSet<>();
        List<String> path = new ArrayList<>();
        dfs(graph, start, visited, path);
        if (path.contains(end)) {
            return path.indexOf(end);
        }
        return -1;
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
        String end_node = "F";
        int result = shortest_path(graph, start_node, end_node);
        System.out.println(result);
    }
}