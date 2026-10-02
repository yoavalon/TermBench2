import java.util.*;

public class sample_0277 {
    public static Map<String, List<String>> initializeGraph(List<String> nodes, List<Pair<String, String>> edges) {
        Map<String, List<String>> graph = new HashMap<>();
        for (String node : nodes) {
            graph.put(node, new ArrayList<>());
        }
        for (Pair<String, String> edge : edges) {
            graph.get(edge.first).add(edge.second);
            graph.get(edge.second).add(edge.first);
        }
        return graph;
    }

    public static List<String> bfsShortestPath(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair<String, List<String>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, new ArrayList<>(Collections.singletonList(start))));
        Set<String> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<String, List<String>> current = queue.poll();
            String node = current.first;
            List<String> path = current.second;
            if (node.equals(end)) {
                return path;
            }
            visited.add(node);
            for (String neighbor : graph.get(node)) {
                if (!visited.contains(neighbor)) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return new ArrayList<>();
    }

    public static List<String> findBoundaryConditions(Map<String, List<String>> graph, String start, String end) {
        List<String> path = bfsShortestPath(graph, start, end);
        if (path.isEmpty()) {
            return new ArrayList<>();
        }
        List<String> boundaryNodes = new ArrayList<>();
        for (int i = 1; i < path.size() - 1; i++) {
            boundaryNodes.add(path.get(i));
        }
        return boundaryNodes;
    }

    public static void main(String[] args) {
        List<String> nodes = Arrays.asList("A", "B", "C", "D", "E", "F");
        List<Pair<String, String>> edges = Arrays.asList(
            new Pair<>("A", "B"),
            new Pair<>("B", "C"),
            new Pair<>("C", "D"),
            new Pair<>("D", "E"),
            new Pair<>("E", "F"),
            new Pair<>("F", "A")
        );
        Map<String, List<String>> graph = initializeGraph(nodes, edges);
        String start = "A";
        String end = "E";
        List<String> boundaryConditions = findBoundaryConditions(graph, start, end);
        System.out.println(boundaryConditions);
    }

    static class Pair<K, V> {
        K first;
        V second;
        Pair(K first, V second) {
            this.first = first;
            this.second = second;
        }
    }
}