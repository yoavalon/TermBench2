public class sample_1853 {
    public static int[] cellular_automata(int steps, int[] cells) {
        for (int _ = 0; _ < steps; _++) {
            int[] new_cells = new int[cells.length];
            for (int i = 1; i < cells.length - 1; i++) {
                new_cells[i] = (cells[i - 1] == cells[i] && cells[i] == cells[i + 1]) ? 0 : 1;
            }
            cells = new_cells;
        }
        return cells;
    }

    public static void main(String[] args) {
        int[] initial_state = {0, 1, 0, 1, 1, 0, 0, 1};
        int steps = 5;
        int[] result = cellular_automata(steps, initial_state);
        for (int cell : result) {
            System.out.print(cell + " ");
        }
    }
}