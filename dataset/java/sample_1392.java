import java.util.*;

public class sample_1392 {
    public static int dijkstra(Map<Integer, Map<Integer, Integer>> graph, int start, int end) {
        PriorityQueue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        Map<Integer, Integer> distances = new HashMap<>();
        for (int node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        queue.add(new int[]{0, start});
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentDistance = current[0];
            int currentNode = current[1];
            if (currentNode == end) {
                return currentDistance;
            }
            for (Map.Entry<Integer, Integer> neighbor : graph.get(currentNode).entrySet()) {
                int distance = currentDistance + neighbor.getValue();
                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                    queue.add(new int[]{distance, neighbor.getKey()});
                }
            }
        }
        return -1;
    }

    public static Map<Integer, Map<Integer, Integer>> buildGraph(List<int[]> edges) {
        Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int weight = edge[2];
            if (!graph.containsKey(a)) {
                graph.put(a, new HashMap<>());
            }
            if (!graph.containsKey(b)) {
                graph.put(b, new HashMap<>());
            }
            graph.get(a).put(b, weight);
            graph.get(b).put(a, weight);
        }
        return graph;
    }

    public static void main(String[] args) {
        List<int[]> edges = Arrays.asList(new int[]{1, 2, 7}, new int[]{1, 3, 9}, new int[]{2, 3, 10}, new int[]{2, 4, 15}, new int[]{3, 4, 11});
        Map<Integer, Map<Integer, Integer>> graph = buildGraph(edges);
        System.out.println(dijkstra(graph, 1, 4));
    }
}