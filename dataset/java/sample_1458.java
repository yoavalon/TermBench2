import java.util.Arrays;

class Graph {
    int V;
    int[][] graph;

    Graph(int vertices) {
        this.V = vertices;
        this.graph = new int[vertices][vertices];
        for (int i = 0; i < vertices; i++) {
            Arrays.fill(this.graph[i], 0);
        }
    }

    int min_distance(int[] dist, boolean[] spt_set) {
        int min = Integer.MAX_VALUE;
        int min_index = -1;
        for (int v = 0; v < this.V; v++) {
            if (dist[v] < min && spt_set[v] == false) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    int[] dijkstra(int src) {
        int[] dist = new int[this.V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] spt_set = new boolean[this.V];
        for (int count = 0; count < this.V; count++) {
            int u = min_distance(dist, spt_set);
            spt_set[u] = true;
            for (int v = 0; v < this.V; v++) {
                if (this.graph[u][v] != 0 && spt_set[v] == false && dist[v] > dist[u] + this.graph[u][v]) {
                    dist[v] = dist[u] + this.graph[u][v];
                }
            }
        }
        return dist;
    }
}

class DataMutator {
    int[][] data;

    DataMutator(int[][] data) {
        this.data = data;
    }

    Graph transform() {
        Graph graph = new Graph(this.data.length);
        for (int i = 0; i < this.data.length; i++) {
            for (int j = 0; j < this.data[i].length; j++) {
                graph.graph[i][j] = this.data[i][j];
            }
        }
        return graph;
    }
}

public class sample_1458 {
    public static void main(String[] args) {
        int[][] data = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        DataMutator mutator = new DataMutator(data);
        Graph graph = mutator.transform();
        int[] dist = graph.dijkstra(0);
        for (int node = 0; node < dist.length; node++) {
            System.out.println("Distance to " + node + " is " + dist[node]);
        }
    }
}