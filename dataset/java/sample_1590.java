public class sample_1590 {
    public static void main(String[] args) {
        int[] a = {1};
        while (true) {
            int b = a[a.length - 1];
            int[] newA = new int[a.length + 1];
            for (int i = 0; i < a.length; i++) {
                newA[i] = a[i];
            }
            newA[a.length] = b + 1;
            a = newA;
            System.out.println(a[a.length - 1]);
        }
    }
}