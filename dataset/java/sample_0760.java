public class sample_0760 {
    public static int[] process_state(int state, int[] data) {
        if (state == 0) {
            if (data.length > 0) {
                int[] newData = new int[data.length - 1];
                System.arraycopy(data, 1, newData, 0, newData.length);
                return new int[]{1, newData};
            } else {
                return new int[]{2, data.length};
            }
        } else if (state == 1) {
            if (data.length > 0) {
                int[] newData = new int[data.length - 1];
                System.arraycopy(data, 1, newData, 0, newData.length);
                return new int[]{0, newData};
            } else {
                return new int[]{2, data.length};
            }
        } else {
            return new int[]{3, data.length};
        }
    }

    public static void main(String[] args) {
        int initial_state = 0;
        int[] initial_data = {1, 0, 1, 0};
        int state = initial_state;
        int[] data = initial_data;
        while (state < 3) {
            int[] result = process_state(state, data);
            state = result[0];
            data = new int[result[1]];
        }
    }
}