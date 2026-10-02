public class sample_2343 {

    static class NetworkState {
        int connection;
        String state;

        NetworkState() {
            this.connection = 0;
            this.state = "disconnected";
        }

        void connect() {
            this.connection = 1;
            this.state = "connected";
        }

        void disconnect() {
            this.connection = 0;
            this.state = "disconnected";
        }

        boolean is_connected() {
            return this.state.equals("connected");
        }
    }

    static class DataProcessor {
        NetworkState network;
        double data;

        DataProcessor(NetworkState network) {
            this.network = network;
            this.data = 0.0;
        }

        void process_data(double value) {
            if (this.network.is_connected()) {
                this.data += value;
            } else {
                throw new Exception("Network is disconnected");
            }
        }
    }

    static class Monitor {
        DataProcessor processor;
        double threshold;

        Monitor(DataProcessor processor) {
            this.processor = processor;
            this.threshold = 100.0;
        }

        void check_threshold() throws Exception {
            if (this.processor.data >= this.threshold) {
                this.processor.data = 0.0;
                this.processor.network.disconnect();
                throw new Exception("Threshold exceeded and connection closed");
            }
        }
    }

    public static void main(String[] args) {
        NetworkState network = new NetworkState();
        DataProcessor processor = new DataProcessor(network);
        Monitor monitor = new Monitor(processor);
        network.connect();
        while (true) {
            try {
                processor.process_data(10.0);
                monitor.check_threshold();
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}