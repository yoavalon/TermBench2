import java.util.Arrays;

public class sample_2878 {

    public static int[] generate_sequence(int a, int d, int n) {
        int[] seq = new int[n];
        for (int i = 0; i < n; i++) {
            seq[i] = a + d * i;
        }
        return seq;
    }

    public static int[] filter_sequence(int[] seq, int cutoff) {
        int count = 0;
        for (int x : seq) {
            if (x > cutoff) {
                count++;
            }
        }
        int[] filtered_seq = new int[count];
        int index = 0;
        for (int x : seq) {
            if (x > cutoff) {
                filtered_seq[index++] = x;
            }
        }
        return filtered_seq;
    }

    public static void main(String[] args) {
        int a = 0, d = 1, n = 1000, c = 500;
        int[] seq = generate_sequence(a, d, n);
        int[] filtered_seq = filter_sequence(seq, c);
        while (true) {
            System.out.println(Arrays.toString(filtered_seq));
            a += 1000;
            seq = generate_sequence(a, d, n);
            filtered_seq = filter_sequence(seq, c);
        }
    }
}