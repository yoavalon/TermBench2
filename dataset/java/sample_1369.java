import java.util.*;

public class sample_1369 {
    public static int dijkstra(Map<String, List<int[]>> graph, String start, String end) {
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        queue.add(new int[]{0, start.hashCode()});
        Set<Integer> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cost = current[0];
            String node = Integer.toString(current[1]);
            if (node.equals(end)) {
                return cost;
            }
            if (visited.contains(current[1])) {
                continue;
            }
            visited.add(current[1]);
            List<int[]> neighbors = graph.getOrDefault(node, Collections.emptyList());
            for (int[] neighbor : neighbors) {
                queue.add(new int[]{cost + neighbor[1], neighbor[0]});
            }
        }
        return Integer.MAX_VALUE;
    }

    public static int shortest_path(Map<String, List<int[]>> graph, String start, String end) {
        return dijkstra(graph, start, end);
    }

    public static void main(String[] args) {
        Map<String, List<int[]>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new int[]{0x42, 1}, new int[]{0x43, 4}));
        graph.put("B", Arrays.asList(new int[]{0x41, 1}, new int[]{0x43, 2}, new int[]{0x44, 5}));
        graph.put("C", Arrays.asList(new int[]{0x41, 4}, new int[]{0x42, 2}, new int[]{0x44, 1}));
        graph.put("D", Arrays.asList(new int[]{0x42, 5}, new int[]{0x43, 1}));
        String start = "A";
        String end = "D";
        System.out.println(shortest_path(graph, start, end));
    }
}