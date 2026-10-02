public class sample_0852 {

    static class DigitalSignalProcessor {
        int[] data;

        DigitalSignalProcessor(int[] data) {
            this.data = data;
        }

        int[] process(int index) {
            if (index >= data.length) {
                return new int[0];
            } else {
                int processed_value = apply_filter(data[index]);
                int[] rest = process(index + 1);
                int[] result = new int[rest.length + 1];
                result[0] = processed_value;
                System.arraycopy(rest, 0, result, 1, rest.length);
                return result;
            }
        }

        int apply_filter(int value) {
            return value * 2;
        }
    }

    static class RecursiveAnalysis {
        DigitalSignalProcessor processor;

        RecursiveAnalysis(DigitalSignalProcessor processor) {
            this.processor = processor;
        }

        java.util.Map<Integer, Boolean> analyze(int index) {
            if (index >= processor.data.length) {
                return new java.util.HashMap<>();
            } else {
                boolean result = analyze_data(processor.data[index]);
                java.util.Map<Integer, Boolean> rest = analyze(index + 1);
                rest.put(index, result);
                return rest;
            }
        }

        boolean analyze_data(int value) {
            return value > 10;
        }
    }

    static class TerminationChecker {
        int[] data;

        TerminationChecker(int[] data) {
            this.data = data;
        }

        boolean check(int index) {
            if (index >= data.length) {
                return true;
            } else {
                return check_condition(data[index]) && check(index + 1);
            }
        }

        boolean check_condition(int value) {
            return value < 100;
        }
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        DigitalSignalProcessor dsp = new DigitalSignalProcessor(data);
        RecursiveAnalysis processor = new RecursiveAnalysis(dsp);
        TerminationChecker checker = new TerminationChecker(data);
        int[] processed_data = dsp.process(0);
        java.util.Map<Integer, Boolean> analysis_results = processor.analyze(0);
        boolean termination_status = checker.check(0);
        for (int value : processed_data) {
            System.out.print(value + " ");
        }
        System.out.println();
        for (java.util.Map.Entry<Integer, Boolean> entry : analysis_results.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
        System.out.println(termination_status);
    }
}