import java.util.*;

public class sample_1316 {
    static List<Character> bfs(Map<Character, Set<Character>> graph, char start, char end) {
        Queue<Pair<Character, List<Character>>> queue = new LinkedList<>();
        queue.add(new Pair<>(start, Collections.singletonList(start)));
        Set<Character> visited = new HashSet<>();
        while (!queue.isEmpty()) {
            Pair<Character, List<Character>> current = queue.poll();
            char node = current.getKey();
            List<Character> path = current.getValue();
            if (node == end) {
                return path;
            }
            visited.add(node);
            for (char neighbor : graph.getOrDefault(node, Collections.emptySet())) {
                if (!visited.contains(neighbor)) {
                    List<Character> newPath = new ArrayList<>(path);
                    newPath.add(neighbor);
                    queue.add(new Pair<>(neighbor, newPath));
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        graph.put('A', new HashSet<>(Arrays.asList('B', 'C')));
        graph.put('B', new HashSet<>(Arrays.asList('A', 'D', 'E')));
        graph.put('C', new HashSet<>(Arrays.asList('A', 'F')));
        graph.put('D', new HashSet<>(Arrays.asList('B')));
        graph.put('E', new HashSet<>(Arrays.asList('B', 'F')));
        graph.put('F', new HashSet<>(Arrays.asList('C', 'E')));
        char startNode = 'A';
        char endNode = 'F';
        List<Character> result = bfs(graph, startNode, endNode);
        if (result != null) {
            System.out.println(result);
        } else {
            System.out.println("No path found");
        }
    }
}

class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}