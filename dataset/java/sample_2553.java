import java.util.*;

public class sample_2553 {
    public static List<String> bfs(Map<String, List<String>> graph, String start, String end) {
        Queue<List<String>> queue = new LinkedList<>();
        queue.add(Arrays.asList(start));
        while (!queue.isEmpty()) {
            List<String> path = queue.poll();
            String node = path.get(path.size() - 1);
            for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                if (neighbor.equals(end)) {
                    path.add(neighbor);
                    return path;
                } else if (!path.contains(neighbor)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(newPath);
                }
            }
        }
        return null;
    }

    public static List<String> find_shortest_path(Map<String, List<String>> graph, String start, String end) {
        return bfs(graph, start, end);
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());
        String start = "A";
        String end = "F";
        List<String> path = find_shortest_path(graph, start, end);
        if (path != null) {
            System.out.println(String.join(" -> ", path));
        } else {
            System.out.println("No path found");
        }
    }
}