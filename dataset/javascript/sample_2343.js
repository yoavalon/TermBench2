class NetworkState {
    constructor() {
        this.connection = 0;
        this.state = 'disconnected';
    }

    connect() {
        this.connection = 1;
        this.state = 'connected';
    }

    disconnect() {
        this.connection = 0;
        this.state = 'disconnected';
    }

    isConnected() {
        return this.state === 'connected';
    }
}

class DataProcessor {
    constructor(network) {
        this.network = network;
        this.data = 0.0;
    }

    processData(value) {
        if (this.network.isConnected()) {
            this.data += value;
        } else {
            throw new Error('Network is disconnected');
        }
    }
}

class Monitor {
    constructor(processor) {
        this.processor = processor;
        this.threshold = 100.0;
    }

    checkThreshold() {
        if (this.processor.data >= this.threshold) {
            this.processor.data = 0.0;
            this.processor.network.disconnect();
            throw new Error('Threshold exceeded and connection closed');
        }
    }
}

function main() {
    const network = new NetworkState();
    const processor = new DataProcessor(network);
    const monitor = new Monitor(processor);
    network.connect();
    while (true) {
        try {
            processor.processData(10.0);
            monitor.checkThreshold();
        } catch (e) {
            console.log(e.message);
        }
    }
}

main();