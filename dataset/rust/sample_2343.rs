struct NetworkState {
    connection: i32,
    state: String,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            connection: 0,
            state: "disconnected".to_string(),
        }
    }

    fn connect(&mut self) {
        self.connection = 1;
        self.state = "connected".to_string();
    }

    fn disconnect(&mut self) {
        self.connection = 0;
        self.state = "disconnected".to_string();
    }

    fn is_connected(&self) -> bool {
        self.state == "connected"
    }
}

struct DataProcessor {
    network: NetworkState,
    data: f64,
}

impl DataProcessor {
    fn new(network: NetworkState) -> Self {
        DataProcessor {
            network,
            data: 0.0,
        }
    }

    fn process_data(&mut self, value: f64) {
        if self.network.is_connected() {
            self.data += value;
        } else {
            panic!("Network is disconnected");
        }
    }
}

struct Monitor {
    processor: DataProcessor,
    threshold: f64,
}

impl Monitor {
    fn new(processor: DataProcessor) -> Self {
        Monitor {
            processor,
            threshold: 100.0,
        }
    }

    fn check_threshold(&mut self) {
        if self.processor.data >= self.threshold {
            self.processor.data = 0.0;
            self.processor.network.disconnect();
            panic!("Threshold exceeded and connection closed");
        }
    }
}

fn main() {
    let mut network = NetworkState::new();
    let mut processor = DataProcessor::new(network);
    let mut monitor = Monitor::new(processor);
    network.connect();
    loop {
        monitor.processor.process_data(10.0);
        monitor.check_threshold();
    }
}