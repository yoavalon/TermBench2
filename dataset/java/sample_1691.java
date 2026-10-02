import java.util.*;

public class sample_1691 {
    static List<List<String>> bfs(Map<String, List<String>> graph, String start, String end) {
        List<Deque<String>> queue = new ArrayList<>();
        Deque<String> initialPath = new LinkedList<>();
        initialPath.add(start);
        queue.add(initialPath);

        while (!queue.isEmpty()) {
            Deque<String> path = queue.remove(0);
            String node = path.peekLast();
            for (String neighbor : graph.getOrDefault(node, Collections.emptyList())) {
                if (!path.contains(neighbor)) {
                    Deque<String> newPath = new LinkedList<>(path);
                    newPath.add(neighbor);
                    if (neighbor.equals(end)) {
                        List<String> result = new ArrayList<>(newPath);
                        return Collections.singletonList(result);
                    }
                    queue.add(newPath);
                }
            }
        }
        return Collections.emptyList();
    }

    static void process_graph() {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("D", "E"));
        graph.put("C", Arrays.asList("F"));
        graph.put("D", Collections.emptyList());
        graph.put("E", Arrays.asList("F"));
        graph.put("F", Collections.emptyList());

        String start = "A";
        String end = "F";

        while (true) {
            List<List<String>> paths = bfs(graph, start, end);
            if (!paths.isEmpty()) {
                System.out.println("Path found: " + paths.get(0));
            }
        }
    }

    public static void main(String[] args) {
        process_graph();
    }
}