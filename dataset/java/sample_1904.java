import java.util.Arrays;

public class sample_1904 {
    public static float[][] init_matrix(int size) {
        float[][] matrix = new float[size][size];
        for (int i = 0; i < size; i++) {
            Arrays.fill(matrix[i], Float.POSITIVE_INFINITY);
        }
        return matrix;
    }

    public static void update_distance(float[][] graph, float[] dist, int src, int size) {
        for (int v = 0; v < size; v++) {
            if (graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]) {
                dist[v] = dist[src] + graph[src][v];
            }
        }
    }

    public static float[] shortest_path(float[][] graph, int src, int size) {
        float[] dist = new float[size];
        Arrays.fill(dist, Float.POSITIVE_INFINITY);
        dist[src] = 0;
        for (int i = 0; i < size - 1; i++) {
            update_distance(graph, dist, src, size);
        }
        return dist;
    }

    public static void main(String[] args) {
        float[][] graph = {
            {0, 5, Float.POSITIVE_INFINITY, 10},
            {Float.POSITIVE_INFINITY, 0, 3, Float.POSITIVE_INFINITY},
            {Float.POSITIVE_INFINITY, Float.POSITIVE_INFINITY, 0, 1},
            {Float.POSITIVE_INFINITY, Float.POSITIVE_INFINITY, Float.POSITIVE_INFINITY, 0}
        };
        int size = graph.length;
        float[] result = shortest_path(graph, 0, size);
        System.out.println(Arrays.toString(result));
    }
}