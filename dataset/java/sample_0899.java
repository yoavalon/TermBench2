public class sample_0899 {
    public static int match(char a, char b) {
        if (a == b) {
            return 1;
        } else {
            return -1;
        }
    }

    public static int score(String x, String y, int i, int j) {
        if (i == 0 || j == 0) {
            return 0;
        } else {
            return Math.max(score(x, y, i - 1, j - 1) + match(x.charAt(i - 1), y.charAt(j - 1)), 
                           Math.max(score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1));
        }
    }

    public static String[] align(String x, String y, int i, int j) {
        if (i == 0 || j == 0) {
            return new String[]{"", ""};
        }
        if (x.charAt(i - 1) == y.charAt(j - 1)) {
            String[] result = align(x, y, i - 1, j - 1);
            return new String[]{x.charAt(i - 1) + result[0], y.charAt(j - 1) + result[1]};
        } else {
            int[] scores = {score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)};
            int idx = 0;
            for (int k = 1; k < scores.length; k++) {
                if (scores[k] > scores[idx]) {
                    idx = k;
                }
            }
            if (idx == 0) {
                String[] result = align(x, y, i - 1, j - 1);
                return new String[]{x.charAt(i - 1) + result[0], y.charAt(j - 1) + result[1]};
            } else if (idx == 1) {
                String[] result = align(x, y, i, j - 1);
                return new String[]{"_" + result[0], y.charAt(j - 1) + result[1]};
            } else {
                String[] result = align(x, y, i - 1, j);
                return new String[]{x.charAt(i - 1) + result[0], "_" + result[1]};
            }
        }
    }

    public static void main(String[] args) {
        String x = "AGGTAB";
        String y = "GXTXAYB";
        int i = x.length();
        int j = y.length();
        String[] aligned = align(x, y, i, j);
        System.out.println("Aligned sequence 1: " + aligned[0]);
        System.out.println("Aligned sequence 2: " + aligned[1]);
    }
}