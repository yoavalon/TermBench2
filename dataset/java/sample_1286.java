import java.util.ArrayList;
import java.util.List;

public class sample_1286 {

    public static List<Double> process_signal(List<Integer> data) {
        double[] dataArray = data.stream().mapToDouble(Integer::doubleValue).toArray();
        double[] filtered = convolve(dataArray, new double[]{0.25, 0.5, 0.25});
        double[] transformed = fft(filtered);
        double[] processed = new double[transformed.length];
        for (int i = 0; i < transformed.length; i++) {
            processed[i] = Math.abs(transformed[i]);
        }
        List<Double> resultList = new ArrayList<>();
        for (double value : processed) {
            resultList.add(value);
        }
        return resultList;
    }

    private static double[] convolve(double[] data, double[] kernel) {
        int n = data.length;
        int k = kernel.length;
        double[] result = new double[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j < k; j++) {
                result[i] += data[i + j] * kernel[j];
            }
        }
        return result;
    }

    private static double[] fft(double[] real) {
        int n = real.length;
        double[] imag = new double[n];
        double[] resultReal = new double[n];
        double[] resultImag = new double[n];
        fftHelper(real, imag, resultReal, resultImag, n, 1);
        for (int i = 0; i < n; i++) {
            resultReal[i] /= n;
            resultImag[i] /= n;
        }
        return resultReal;
    }

    private static void fftHelper(double[] real, double[] imag, double[] resultReal, double[] resultImag, int n, int step) {
        if (n == 1) {
            resultReal[0] = real[0];
            resultImag[0] = imag[0];
            return;
        }
        double[] evenReal = new double[n / 2];
        double[] evenImag = new double[n / 2];
        double[] oddReal = new double[n / 2];
        double[] oddImag = new double[n / 2];
        for (int i = 0; i < n / 2; i++) {
            evenReal[i] = real[2 * i];
            evenImag[i] = imag[2 * i];
            oddReal[i] = real[2 * i + 1];
            oddImag[i] = imag[2 * i + 1];
        }
        fftHelper(evenReal, evenImag, resultReal, resultImag, n / 2, 2 * step);
        fftHelper(oddReal, oddImag, resultReal, resultImag, n / 2, 2 * step);
        for (int i = 0; i < n / 2; i++) {
            double t = -2 * Math.PI * i / n * step;
            double cosT = Math.cos(t);
            double sinT = Math.sin(t);
            resultReal[i] = resultReal[i / 2] + cosT * resultReal[i / 2 + n / 2] - sinT * resultImag[i / 2 + n / 2];
            resultImag[i] = resultImag[i / 2] + cosT * resultImag[i / 2 + n / 2] + sinT * resultReal[i / 2 + n / 2];
            resultReal[i + n / 2] = resultReal[i / 2] - cosT * resultReal[i / 2 + n / 2] + sinT * resultImag[i / 2 + n / 2];
            resultImag[i + n / 2] = resultImag[i / 2] - cosT * resultImag[i / 2 + n / 2] - sinT * resultReal[i / 2 + n / 2];
        }
    }

    public static void main(String[] args) {
        List<Integer> main_data = List.of(1, 2, 3, 4, 5);
        List<Double> result = process_signal(main_data);
        System.out.println(result);
    }
}