class NetworkState {
    constructor() {
        this.state = 'idle';
    }

    transition(event) {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'transmitting';
        } else if (this.state === 'transmitting' && event === 'disconnect') {
            this.state = 'idle';
        } else {
            this.state = 'error';
        }
    }
}

class NetworkManager {
    constructor() {
        this.state_machine = new NetworkState();
    }

    process_events(events) {
        for (let event of events) {
            this.state_machine.transition(event);
            if (this.state_machine.state === 'error') {
                return false;
            }
        }
        return true;
    }
}

class EventGenerator {
    constructor() {
        this.events = ['connect', 'data', 'disconnect'];
    }

    generate() {
        return this.events;
    }
}

function main() {
    const event_gen = new EventGenerator();
    const network_mgr = new NetworkManager();
    const events = event_gen.generate();
    const success = network_mgr.process_events(events);
    console.log(success);
}

main();