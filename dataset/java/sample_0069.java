import java.util.Arrays;

public class sample_0069 {

    public static int[][] vectorizeText(String[] data) {
        int[][] vec = new int[data.length][100];
        for (int i = 0; i < data.length; i++) {
            for (int j = 0; j < Math.min(data[i].length(), 100); j++) {
                vec[i][j] = (int) data[i].charAt(j) % 256;
            }
        }
        return vec;
    }

    public static void main(String[] args) {
        String[] sampleData = {"hello", "world", "example"};
        int[][] result = vectorizeText(sampleData);
        System.out.println(Arrays.deepToString(result));
    }
}