import java.util.*;

public class sample_0776 {
    public static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String end, List<String> path) {
        path = new ArrayList<>(path);
        path.add(start);
        if (start.equals(end)) {
            return path;
        }
        if (!graph.containsKey(start)) {
            return null;
        }
        List<String> shortest = null;
        for (String node : graph.get(start)) {
            if (!path.contains(node)) {
                List<String> newpath = find_shortest_path(graph, node, end, path);
                if (newpath != null) {
                    if (shortest == null || newpath.size() < shortest.size()) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("C", "D"));
        graph.put("C", Arrays.asList("D"));
        graph.put("D", Arrays.asList("C"));
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Arrays.asList("C"));
        String start = "A";
        String end = "D";
        System.out.println(find_shortest_path(graph, start, end));
    }
}