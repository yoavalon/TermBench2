class NetworkState {
    constructor() {
        this.connection = false;
        this.data = 0.0;
        this.threshold = 0.5;
    }

    connect() {
        this.connection = true;
        this.data = 0.1;
    }

    disconnect() {
        this.connection = false;
        this.data = 0.0;
    }

    transmit() {
        if (this.connection) {
            this.data += 0.01;
            if (this.data >= this.threshold) {
                this.disconnect();
            }
        }
    }
}

class NetworkMonitor {
    constructor() {
        this.state = new NetworkState();
    }

    observe() {
        if (!this.state.connection) {
            this.state.connect();
        } else {
            this.state.transmit();
        }
    }
}

class NetworkAnalyzer {
    constructor(monitor) {
        this.monitor = monitor;
    }

    analyze() {
        while (true) {
            this.monitor.observe();
        }
    }
}

function main() {
    const monitor = new NetworkMonitor();
    const analyzer = new NetworkAnalyzer(monitor);
    analyzer.analyze();
}

main();