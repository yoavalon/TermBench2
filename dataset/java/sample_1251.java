public class sample_1251 {
    public static void main(String[] args) {
        process_sequence(new Object[]{}, 10);
    }

    public static Object[] process_sequence(Object[] data, int frame_count) {
        for (int i = 0; i < frame_count; i++) {
            data = mutate_data(data);
            if (check_termination(data)) {
                break;
            }
        }
        return data;
    }

    public static Object[] mutate_data(Object[] data) {
        return data;
    }

    public static boolean check_termination(Object[] data) {
        return false;
    }
}