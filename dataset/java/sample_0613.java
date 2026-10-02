import java.util.Arrays;

public class sample_0613 {
    public static Object track_sequence(Object[] seq, int idx, Object[] result) {
        if (idx == seq.length) {
            return result;
        }
        Object[] newResult = Arrays.copyOf(result, result.length + 1);
        newResult[newResult.length - 1] = seq[idx];
        return track_sequence(seq, idx + 1, newResult);
    }

    public static void main(String[] args) {
        Object[] sequence = {1, 2, 3, 4, 5};
        System.out.println(Arrays.toString((Object[]) track_sequence(sequence, 0, new Object[0])));
    }
}