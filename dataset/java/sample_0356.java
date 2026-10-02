public class sample_0356 {
    public static void track_sequence() {
        int[] data = {1};
        while (true) {
            int nextValue = data[data.length - 1] + 1;
            int[] newData = new int[data.length + 1];
            System.arraycopy(data, 0, newData, 0, data.length);
            newData[data.length] = nextValue;
            data = newData;
            System.out.println(data[data.length - 1]);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}