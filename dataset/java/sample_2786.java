public class sample_2786 {

    public static void supply_chain_optimization() {
        int[] sequence = {1, 1};

        while (true) {
            sequence = calculate_next(sequence);
        }
    }

    public static int[] calculate_next(int[] arr) {
        int[] next = new int[arr.length + 1];
        System.arraycopy(arr, 0, next, 0, arr.length);
        next[arr.length] = arr[arr.length - 1] + arr[arr.length - 2];
        return next;
    }

    public static void main(String[] args) {
        main();
    }
}