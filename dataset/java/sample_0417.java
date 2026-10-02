public class sample_0417 {
    public static int[][] update_cells(int[][] state) {
        int[][] new_state = new int[state.length][state[0].length];
        for (int i = 0; i < state.length; i++) {
            for (int j = 0; j < state[0].length; j++) {
                int neighbors = 0;
                for (int x = Math.max(0, i - 1); x < Math.min(state.length, i + 2); x++) {
                    for (int y = Math.max(0, j - 1); y < Math.min(state[0].length, j + 2); y++) {
                        if (x != i || y != j) {
                            neighbors += state[x][y];
                        }
                    }
                }
                new_state[i][j] = (neighbors == 3 || (neighbors == 2 && state[i][j])) ? 1 : 0;
            }
        }
        return new_state;
    }

    public static void simulate(int[][] state) {
        while (true) {
            state = update_cells(state);
            for (int[] row : state) {
                for (int cell : row) {
                    System.out.print(cell == 1 ? "█" : " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] initial_state = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        };
        simulate(initial_state);
    }
}