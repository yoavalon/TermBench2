import java.util.*;

public class sample_0715 {
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

    public static List<String> shortest_path(Map<String, List<String>> graph, String start, String end) {
        List<String> path = dfs(graph, start, end, new ArrayList<>(), new HashSet<>());
        return path != null ? path : new ArrayList<>();
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", new ArrayList<>(Arrays.asList("B", "C")));
        graph.put("B", new ArrayList<>(Arrays.asList("C", "D")));
        graph.put("C", new ArrayList<>(Arrays.asList("D")));
        graph.put("D", new ArrayList<>(Arrays.asList("E")));
        String start = "A";
        String end = "E";
        List<String> result = shortest_path(graph, start, end);
        System.out.println(result);
    }
}