class NetworkState {
    current_state: string;

    constructor() {
        this.current_state = 'idle';
    }

    transition(event: string): void {
        if (this.current_state === 'idle' && event === 'connect') {
            this.current_state = 'connected';
        } else if (this.current_state === 'connected' && event === 'data') {
            this.current_state = 'transmitting';
        } else if (this.current_state === 'transmitting' && event === 'disconnect') {
            this.current_state = 'idle';
        } else if (this.current_state === 'idle' && event === 'error') {
            this.current_state = 'error_state';
        } else if (this.current_state === 'error_state' && event === 'recover') {
            this.current_state = 'idle';
        }
    }

    process_events(events: string[]): void {
        for (const event of events) {
            this.transition(event);
        }
    }
}

class NetworkController {
    state_machine: NetworkState;
    events: string[];

    constructor() {
        this.state_machine = new NetworkState();
        this.events = [];
    }

    add_event(event: string): void {
        this.events.push(event);
    }

    run(): void {
        while (true) {
            this.state_machine.process_events(this.events);
        }
    }
}

function main(): void {
    const controller = new NetworkController();
    controller.add_event('connect');
    controller.add_event('data');
    controller.add_event('disconnect');
    controller.add_event('connect');
    controller.add_event('data');
    controller.add_event('error');
    controller.add_event('recover');
    controller.run();
}

main();