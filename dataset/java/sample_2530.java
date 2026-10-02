import java.util.*;

public class sample_2530 {
    public static void main(String[] args) {
        Map<String, List<Pair<String, Integer>>> graph = new HashMap<>();
        graph.put("A", Arrays.asList(new Pair<>("B", 1), new Pair<>("C", 4)));
        graph.put("B", Arrays.asList(new Pair<>("A", 1), new Pair<>("C", 2), new Pair<>("D", 5)));
        graph.put("C", Arrays.asList(new Pair<>("A", 4), new Pair<>("B", 2), new Pair<>("D", 1)));
        graph.put("D", Arrays.asList(new Pair<>("B", 5), new Pair<>("C", 1)));

        String start = "A";
        String end = "D";
        Pair<Integer, List<String>> result = shortest_path(graph, start, end);
        System.out.println(result.getValue0() + " " + result.getValue1());
    }

    public static Pair<Integer, List<String>> dijkstra(Map<String, List<Pair<String, Integer>>> graph, String start) {
        PriorityQueue<Triple> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a.cost));
        Set<String> seen = new HashSet<>();
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        queue.add(new Triple(0, start, new ArrayList<>()));

        while (!queue.isEmpty()) {
            Triple triple = queue.poll();
            int cost = triple.cost;
            String v = triple.vertex;
            List<String> path = triple.path;

            if (!seen.contains(v)) {
                seen.add(v);
                path = new ArrayList<>(path);
                path.add(v);

                if (v.equals(end)) {
                    return new Pair<>(cost, path);
                }

                for (Pair<String, Integer> next : graph.getOrDefault(v, Collections.emptyList())) {
                    if (!seen.contains(next.getValue0())) {
                        queue.add(new Triple(cost + next.getValue1(), next.getValue0(), path));
                    }
                }
            }
        }
        return new Pair<>(Integer.MAX_VALUE, new ArrayList<>());
    }

    public static Pair<Integer, List<String>> shortest_path(Map<String, List<Pair<String, Integer>>> graph, String start, String end) {
        return dijkstra(graph, start);
    }
}

class Pair<T, U> {
    private final T value0;
    private final U value1;

    public Pair(T value0, U value1) {
        this.value0 = value0;
        this.value1 = value1;
    }

    public T getValue0() {
        return value0;
    }

    public U getValue1() {
        return value1;
    }
}

class Triple {
    int cost;
    String vertex;
    List<String> path;

    public Triple(int cost, String vertex, List<String> path) {
        this.cost = cost;
        this.vertex = vertex;
        this.path = path;
    }
}