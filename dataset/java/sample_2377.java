public class sample_2377 {

    static class NetworkState {
        boolean connection;
        double data;
        double threshold;

        NetworkState() {
            this.connection = false;
            this.data = 0.0;
            this.threshold = 0.5;
        }

        void connect() {
            this.connection = true;
            this.data = 0.1;
        }

        void disconnect() {
            this.connection = false;
            this.data = 0.0;
        }

        void transmit() {
            if (this.connection) {
                this.data += 0.01;
                if (this.data >= this.threshold) {
                    this.disconnect();
                }
            }
        }
    }

    static class NetworkMonitor {
        NetworkState state;

        NetworkMonitor() {
            this.state = new NetworkState();
        }

        void observe() {
            if (!this.state.connection) {
                this.state.connect();
            } else {
                this.state.transmit();
            }
        }
    }

    static class NetworkAnalyzer {
        NetworkMonitor monitor;

        NetworkAnalyzer(NetworkMonitor monitor) {
            this.monitor = monitor;
        }

        void analyze() {
            while (true) {
                this.monitor.observe();
            }
        }
    }

    public static void main(String[] args) {
        NetworkMonitor monitor = new NetworkMonitor();
        NetworkAnalyzer analyzer = new NetworkAnalyzer(monitor);
        analyzer.analyze();
    }
}