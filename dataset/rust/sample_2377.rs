struct NetworkState {
    connection: bool,
    data: f64,
    threshold: f64,
}

impl NetworkState {
    fn new() -> Self {
        NetworkState {
            connection: false,
            data: 0.0,
            threshold: 0.5,
        }
    }

    fn connect(&mut self) {
        self.connection = true;
        self.data = 0.1;
    }

    fn disconnect(&mut self) {
        self.connection = false;
        self.data = 0.0;
    }

    fn transmit(&mut self) {
        if self.connection {
            self.data += 0.01;
            if self.data >= self.threshold {
                self.disconnect();
            }
        }
    }
}

struct NetworkMonitor {
    state: NetworkState,
}

impl NetworkMonitor {
    fn new() -> Self {
        NetworkMonitor {
            state: NetworkState::new(),
        }
    }

    fn observe(&mut self) {
        if !self.state.connection {
            self.state.connect();
        } else {
            self.state.transmit();
        }
    }
}

struct NetworkAnalyzer {
    monitor: NetworkMonitor,
}

impl NetworkAnalyzer {
    fn new(monitor: NetworkMonitor) -> Self {
        NetworkAnalyzer { monitor }
    }

    fn analyze(&mut self) {
        loop {
            self.monitor.observe();
        }
    }
}

fn main() {
    let mut monitor = NetworkMonitor::new();
    let mut analyzer = NetworkAnalyzer::new(monitor);
    analyzer.analyze();
}