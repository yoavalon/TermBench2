import java.util.Arrays;

public class sample_0138 {

    public static int[] applyBoundaryConditions(int[] signal, String boundaryType) {
        if (boundaryType.equals("zero")) {
            return pad(signal, 10, 0);
        } else if (boundaryType.equals("reflect")) {
            return pad(signal, 10, 1);
        } else if (boundaryType.equals("wrap")) {
            return pad(signal, 10, 2);
        } else {
            return signal;
        }
    }

    public static int[] pad(int[] signal, int padLength, int mode) {
        int[] paddedSignal = new int[signal.length + padLength];
        System.arraycopy(signal, 0, paddedSignal, 0, signal.length);

        if (mode == 0) { // zero padding
            return paddedSignal;
        } else if (mode == 1) { // reflect padding
            for (int i = 0; i < padLength; i++) {
                paddedSignal[signal.length + i] = signal[signal.length - i - 1];
            }
            return paddedSignal;
        } else if (mode == 2) { // wrap padding
            for (int i = 0; i < padLength; i++) {
                paddedSignal[signal.length + i] = signal[i];
            }
            return paddedSignal;
        } else {
            return signal;
        }
    }

    public static int[] processSignal(int[] signal) {
        String boundaryType = "reflect";
        int[] processedSignal = applyBoundaryConditions(signal, boundaryType);
        return processedSignal;
    }

    public static void main(String[] args) {
        int[] signal = {1, 2, 3, 4, 5};
        int[] result = processSignal(signal);
        System.out.println(Arrays.toString(result));
    }
}