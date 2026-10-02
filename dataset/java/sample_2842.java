public class sample_2842 {
    public static void main(String[] args) {
        int state = 0;
        int[] sequence = {1};
        while (true) {
            int[] result = generate_sequence(state, sequence);
            state = result[0];
            sequence = append(sequence, result[1]);
        }
    }

    public static int[] generate_sequence(int state, int[] sequence) {
        int next_state;
        int next_value;
        if (state == 0) {
            next_state = 1;
            next_value = sequence[sequence.length - 1] + 1;
        } else if (state == 1) {
            next_state = 2;
            next_value = sequence[sequence.length - 1] * 2;
        } else if (state == 2) {
            next_state = 0;
            next_value = sequence[sequence.length - 1] - 1;
        }
        return new int[]{next_state, next_value};
    }

    public static int[] append(int[] array, int value) {
        int[] newArray = new int[array.length + 1];
        System.arraycopy(array, 0, newArray, 0, array.length);
        newArray[array.length] = value;
        return newArray;
    }
}