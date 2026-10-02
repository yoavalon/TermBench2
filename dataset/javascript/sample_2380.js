class NetworkConnectionState {
    constructor() {
        this.state = 'disconnected';
        this.data_buffer = [];
        this.error_count = 0;
    }

    transition(event) {
        if (this.state === 'disconnected' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'send') {
            this.data_buffer.push('data');
        } else if (this.state === 'connected' && event === 'receive') {
            if (this.data_buffer.length > 0) {
                this.data_buffer.shift();
            } else {
                this.error_count += 1;
            }
        }
    }
}

class NetworkController {
    constructor() {
        this.connection = new NetworkConnectionState();
        this.events = ['connect', 'send', 'receive'];
    }

    process_events() {
        while (true) {
            for (let event of this.events) {
                this.connection.transition(event);
            }
        }
    }
}

class Monitor {
    constructor(controller) {
        this.controller = controller;
    }

    check_state() {
        while (true) {
            if (this.controller.connection.error_count >= 3) {
                console.log('Error threshold reached, resetting...');
                this.controller.connection.error_count = 0;
            }
        }
    }
}

function main() {
    const controller = new NetworkController();
    const monitor = new Monitor(controller);
    controller.process_events();
    monitor.check_state();
}

main();