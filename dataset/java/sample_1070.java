import java.util.*;

public class sample_1070 {
    static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String end, Set<String> visited) {
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
                List<String> path = find_shortest_path(graph, neighbor, end, visited);
                if (path != null) {
                    path.add(0, start);
                    return path;
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Arrays.asList("G"));
        graph.put("E", Arrays.asList("F", "H"));
        graph.put("F", Arrays.asList("G"));
        graph.put("G", Arrays.asList("H"));
        graph.put("H", new ArrayList<>());
        String start = "A";
        String end = "H";
        while (true) {
            List<String> path = find_shortest_path(graph, start, end, null);
            if (path != null) {
                System.out.println(path);
            }
        }
    }
}