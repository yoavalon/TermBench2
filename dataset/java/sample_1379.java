public class sample_1379 {
    public static void optimize_routes(int[][] routes, int[] demands, int[] capacities) {
        for (int i = 0; i < routes.length; i++) {
            if (demands[i] > capacities[i]) {
                routes[i] = redistribute_load(routes, demands, capacities, i);
            }
        }
    }

    public static int[] redistribute_load(int[][] routes, int[] demands, int[] capacities, int index) {
        int excess = demands[index] - capacities[index];
        for (int j = 0; j < routes.length; j++) {
            if (j != index && capacities[j] > 0) {
                int transfer = Math.min(excess, capacities[j]);
                demands[j] += transfer;
                demands[index] -= transfer;
                excess -= transfer;
                if (excess == 0) {
                    break;
                }
            }
        }
        return routes[index];
    }

    public static void main(String[] args) {
        int[][] routes = {{1, 2}, {3, 4}, {5, 6}};
        int[] demands = {10, 15, 20};
        int[] capacities = {10, 10, 10};
        optimize_routes(routes, demands, capacities);
        for (int i = 0; i < routes.length; i++) {
            System.out.print("[");
            for (int j = 0; j < routes[i].length; j++) {
                System.out.print(routes[i][j]);
                if (j < routes[i].length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}