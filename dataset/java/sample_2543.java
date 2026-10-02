public class sample_2543 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = i * (i + 1) / 2;
        }
        return sequence;
    }

    public static java.util.HashMap<Integer, Integer> analyze_sequence(int[] seq) {
        java.util.HashMap<Integer, Integer> result = new java.util.HashMap<>();
        for (int index = 0; index < seq.length; index++) {
            result.put(seq[index], index);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] seq = generate_sequence(10);
        java.util.HashMap<Integer, Integer> analysis = analyze_sequence(seq);
        System.out.println(analysis);
    }
}