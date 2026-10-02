import java.util.*;

public class sample_1967 {
    public static void dijkstra(Map<String, List<Pair<String, Double>>> graph, String start, String end, PriorityQueue<Triple<Double, String, List<String>>> q, Set<String> visited) {
        while (!q.isEmpty()) {
            Triple<Double, String, List<String>> current = q.poll();
            double cost = current.first;
            String v = current.second;
            List<String> path = current.third;
            if (!visited.contains(v)) {
                visited.add(v);
                path = new ArrayList<>(path);
                path.add(v);
                if (v.equals(end)) {
                    System.out.println('Shortest path cost: ' + cost);
                    System.out.println('Shortest path: ' + path);
                    return;
                }
                for (Pair<String, Double> next : graph.get(v)) {
                    if (!visited.contains(next.first)) {
                        List<String> newPath = new ArrayList<>(path);
                        q.add(new Triple<>(cost + next.second, next.first, newPath));
                    }
                }
            }
        }
    }

    public static void find_shortest_path(Map<String, List<Pair<String, Double>>> graph, String start, String end) {
        PriorityQueue<Triple<Double, String, List<String>>> q = new PriorityQueue<>(Comparator.comparingDouble(t -> t.first));
        q.add(new Triple<>(0.0, start, new ArrayList<>()));
        Set<String> visited = new HashSet<>();
        dijkstra(graph, start, end, q, visited);
    }

    public static void main(String[] args) {
        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Pair<>("B", 1.0), new Pair<>("C", 4.0)));
        graph.put("B", Arrays.asList(new Pair<>("C", 2.0), new Pair<>("D", 5.0)));
        graph.put("C", Arrays.asList(new Pair<>("D", 1.0)));
        graph.put("D", new ArrayList<>());
        String start = "A";
        String end = "D";
        find_shortest_path(graph, start, end);
    }
}

class Pair<K, V> {
    K first;
    V second;

    Pair(K first, V second) {
        this.first = first;
        this.second = second;
    }
}

class Triple<F, S, T> {
    F first;
    S second;
    T third;

    Triple(F first, S second, T third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}