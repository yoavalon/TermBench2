import java.util.*;

public class sample_0701 {
    public static void dfs(Map<String, List<String>> graph, String node, Set<String> visited, List<String> path, List<List<String>> paths) {
        visited.add(node);
        path.add(node);
        if (graph.get(node).size() == 0) {
            paths.add(new ArrayList<>(path));
        }
        for (String neighbor : graph.get(node)) {
            if (!visited.contains(neighbor)) {
                dfs(graph, neighbor, visited, path, paths);
            }
        }
        path.remove(path.size() - 1);
        visited.remove(node);
    }

    public static List<String> shortest_path(Map<String, List<String>> graph, String start, String end) {
        List<List<String>> paths = new ArrayList<>();
        dfs(graph, start, new HashSet<>(), new ArrayList<>(), paths);
        int min_length = Integer.MAX_VALUE;
        List<String> best_path = null;
        for (List<String> path : paths) {
            if (path.get(path.size() - 1).equals(end) && path.size() < min_length) {
                min_length = path.size();
                best_path = path;
            }
        }
        return best_path;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D"));
        graph.put("C", Arrays.asList("D"));
        graph.put("D", Collections.emptyList());
        String start_node = "A";
        String end_node = "D";
        System.out.println(shortest_path(graph, start_node, end_node));
    }
}