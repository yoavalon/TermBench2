import java.util.*;

public class sample_0752 {
    public static List<String> dfs(Map<String, List<String>> graph, String start, String end, List<String> path, Set<String> visited) {
        path.add(start);
        visited.add(start);
        if (start.equals(end)) {
            return path;
        }
        for (String neighbor : graph.get(start)) {
            if (!visited.contains(neighbor)) {
                List<String> result = dfs(graph, neighbor, end, new ArrayList<>(path), visited);
                if (result != null) {
                    return result;
                }
            }
        }
        return null;
    }

    public static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String end) {
        return dfs(graph, start, end, new ArrayList<>(), new HashSet<>());
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());

        List<String> path = find_shortest_path(graph, "A", "F");
        if (path != null) {
            System.out.println("Path found: " + path);
        } else {
            System.out.println("No path found");
        }
    }
}