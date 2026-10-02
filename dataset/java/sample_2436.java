public class sample_2436 {
    public static void main(String[] args) {
        int n = 10;
        int a = 0, b = 1;
        java.util.ArrayList<Integer> sequence = new java.util.ArrayList<>();
        sequence.add(a);
        sequence.add(b);
        for (int i = 2; i < n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
            sequence.add(b);
        }
        System.out.println(sequence);
    }
}