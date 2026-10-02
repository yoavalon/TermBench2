import java.util.*;

public class sample_2457 {
    public static int f(Map<String, List<String>> g, String s, String e) {
        Queue<Pair> q = new LinkedList<>();
        Set<String> v = new HashSet<>();
        q.add(new Pair(s, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            String n = p.n;
            int d = p.d;
            if (n.equals(e)) {
                return d;
            }
            v.add(n);
            List<String> neighbors = g.getOrDefault(n, new ArrayList<>());
            for (String x : neighbors) {
                if (!v.contains(x)) {
                    q.add(new Pair(x, d + 1));
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Map<String, List<String>> g = new HashMap<>();
        g.put("A", Arrays.asList("B", "C"));
        g.put("B", Arrays.asList("D"));
        g.put("C", Arrays.asList("D"));
        g.put("D", Arrays.asList("E"));
        g.put("E", new ArrayList<>());
        String s = "A";
        String e = "E";
        System.out.println(f(g, s, e));
    }
}

class Pair {
    String n;
    int d;

    Pair(String n, int d) {
        this.n = n;
        this.d = d;
    }
}