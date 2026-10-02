import java.util.*;

public class sample_0774 {
    public static List<String> dfs(Map<String, List<String>> graph, String start, String end, Set<String> visited) {
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
                List<String> path = dfs(graph, neighbor, end, visited);
                if (path != null) {
                    path.add(0, start);
                    return path;
                }
            }
        }
        return null;
    }

    public static int shortest_path(Map<String, List<String>> graph, String start, String end) {
        List<String> path = dfs(graph, start, end);
        if (path != null) {
            return path.size() - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Arrays.asList("G"));
        graph.put("E", Arrays.asList("G"));
        graph.put("F", Arrays.asList("G"));
        graph.put("G", new ArrayList<>());

        String start_node = "A";
        String end_node = "G";
        int result = shortest_path(graph, start_node, end_node);
        System.out.println(result);
    }
}