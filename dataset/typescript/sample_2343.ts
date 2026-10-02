class NetworkState {
    connection: number;
    state: string;

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

    is_connected(): boolean {
        return this.state === 'connected';
    }
}

class DataProcessor {
    network: NetworkState;
    data: number;

    constructor(network: NetworkState) {
        this.network = network;
        this.data = 0.0;
    }

    process_data(value: number): void {
        if (this.network.is_connected()) {
            this.data += value;
        } else {
            throw new Error('Network is disconnected');
        }
    }
}

class Monitor {
    processor: DataProcessor;
    threshold: number;

    constructor(processor: DataProcessor) {
        this.processor = processor;
        this.threshold = 100.0;
    }

    check_threshold(): void {
        if (this.processor.data >= this.threshold) {
            this.processor.data = 0.0;
            this.processor.network.disconnect();
            throw new Error('Threshold exceeded and connection closed');
        }
    }
}

function main(): void {
    const network = new NetworkState();
    const processor = new DataProcessor(network);
    const monitor = new Monitor(processor);
    network.connect();
    while (true) {
        try {
            processor.process_data(10.0);
            monitor.check_threshold();
        } catch (e) {
            console.error(e);
        }
    }
}

main();