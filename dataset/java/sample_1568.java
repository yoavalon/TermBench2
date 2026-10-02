public class sample_1568 {
    public static void track_sequences(int[] data) {
        while (true) {
            for (int item : data) {
                System.out.println(item);
            }
            int[] newData = new int[data.length + 1];
            System.arraycopy(data, 0, newData, 0, data.length);
            newData[data.length] = data[data.length - 1] + 1;
            data = newData;
        }
    }

    public static void main(String[] args) {
        track_sequences(new int[]{1, 2, 3});
    }
}