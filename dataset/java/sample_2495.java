import java.util.*;

public class sample_2495 {
    public static int find_shortest_path(Map<String, List<String>> graph, String start, String end) {
        Queue<Pair> q = new LinkedList<>();
        Set<String> v = new HashSet<>();
        q.add(new Pair(start, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            String n = p.node;
            int d = p.distance;
            if (n.equals(end)) {
                return d;
            }
            v.add(n);
            for (String nxt : graph.getOrDefault(n, Collections.emptyList())) {
                if (!v.contains(nxt)) {
                    q.add(new Pair(nxt, d + 1));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<String>> g = new HashMap<>();
        g.put("A", Arrays.asList("B", "C"));
        g.put("B", Arrays.asList("D", "E"));
        g.put("C", Arrays.asList("F"));
        g.put("D", Arrays.asList("G"));
        g.put("E", Arrays.asList("F"));
        g.put("F", Arrays.asList("G"));
        g.put("G", Collections.emptyList());
        int result = find_shortest_path(g, "A", "G");
        System.out.println(result);
    }
}

class Pair {
    String node;
    int distance;

    Pair(String node, int distance) {
        this.node = node;
        this.distance = distance;
    }
}