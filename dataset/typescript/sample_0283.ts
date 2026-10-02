class NetworkStateMachine {
    states: string[];
    transitions: { [key: string]: string };
    current_state: string;

    constructor(states: string[], transitions: { [key: string]: string }) {
        this.states = states;
        this.transitions = transitions;
        this.current_state = states[0];
    }

    transition(event: string): void {
        const key = `${this.current_state},${event}`;
        if (this.transitions.hasOwnProperty(key)) {
            this.current_state = this.transitions[key];
        } else {
            throw new Error('Invalid transition');
        }
    }

    is_terminal(): boolean {
        return ['disconnected', 'error'].includes(this.current_state);
    }
}

class EventManager {
    events: string[];
    index: number;

    constructor(events: string[]) {
        this.events = events;
        this.index = 0;
    }

    get_next_event(): string | null {
        if (this.index < this.events.length) {
            const event = this.events[this.index];
            this.index += 1;
            return event;
        } else {
            return null;
        }
    }
}

function main(): void {
    const states = ['idle', 'connected', 'disconnected', 'error'];
    const transitions: { [key: string]: string } = {
        'idle,connect': 'connected',
        'connected,disconnect': 'disconnected',
        'connected,error': 'error',
        'disconnected,connect': 'connected',
        'error,reset': 'idle'
    };
    const events = ['connect', 'disconnect', 'error', 'reset', 'connect', 'disconnect', 'connect', 'error', 'reset'];
    const network_machine = new NetworkStateMachine(states, transitions);
    const event_manager = new EventManager(events);

    while (true) {
        const event = event_manager.get_next_event();
        if (event === null || network_machine.is_terminal()) {
            break;
        }
        network_machine.transition(event);
    }

    console.log(`Final state: ${network_machine.current_state}`);
}

main();