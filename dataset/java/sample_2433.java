public class sample_2433 {
    public static void optimize_logistics(int[] data) {
        int[] seq = new int[data.length];
        int total = 0;
        int cap = 50;
        int index = 0;
        for (int item : data) {
            if (total + item <= cap) {
                seq[index++] = item;
                total += item;
            } else {
                break;
            }
        }
        for (int i = 0; i < index; i++) {
            System.out.print(seq[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] data = {10, 20, 30, 40, 50, 60};
        optimize_logistics(data);
    }
}