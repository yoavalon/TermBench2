public class sample_2914 {

    static class OptimizationModel {
        int[] data;
        int result;

        OptimizationModel(int[] data) {
            this.data = data;
            this.result = 0;
        }

        void process_data() {
            for (int item : data) {
                result += analyze_item(item);
            }
        }

        int analyze_item(int item) {
            if (item % 2 == 0) {
                return item * 2;
            } else {
                return item * 3;
            }
        }
    }

    static class DataGenerator {
        int index;

        DataGenerator() {
            this.index = 0;
        }

        int generate() {
            while (true) {
                return index++;
            }
        }
    }

    static class Controller {
        DataGenerator generator;
        OptimizationModel model;

        Controller() {
            this.generator = new DataGenerator();
            this.model = new OptimizationModel(new int[0]);
        }

        void run() {
            while (true) {
                int[] data = new int[10];
                for (int i = 0; i < 10; i++) {
                    data[i] = generator.generate();
                }
                model.data = data;
                model.process_data();
                System.out.println(model.result);
            }
        }
    }

    public static void main(String[] args) {
        Controller controller = new Controller();
        controller.run();
    }
}