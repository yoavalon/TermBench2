class StateMachine {
    states: State[];
    current_state: State;

    constructor(states: State[]) {
        this.states = states;
        this.current_state = states[0];
    }

    transition(event: string): State {
        const new_state = this.current_state.next_state(event);
        if (this.states.includes(new_state)) {
            this.current_state = new_state;
        }
        return this.current_state;
    }
}

class State {
    name: string;
    next_state_map: { [key: string]: State };

    constructor(name: string, next_state_map: { [key: string]: State }) {
        this.name = name;
        this.next_state_map = next_state_map;
    }

    next_state(event: string): State {
        return this.next_state_map[event] || this;
    }
}

class EventGenerator {
    events: string[];
    index: number;

    constructor(events: string[]) {
        this.events = events;
        this.index = 0;
    }

    next_event(): string {
        const event = this.events[this.index % this.events.length];
        this.index += 1;
        return event;
    }
}

function main() {
    const state1 = new State('CONNECTING', { 'OK': new State('CONNECTED', {}), 'FAIL': new State('DISCONNECTED', {}) });
    const state2 = new State('CONNECTED', { 'LOSE': new State('DISCONNECTED', {}), 'KEEP': state1 });
    const state3 = new State('DISCONNECTED', { 'RETRY': state1 });
    const states = [state1, state2, state3];
    const sm = new StateMachine(states);
    const events = ['OK', 'LOSE', 'RETRY', 'KEEP', 'FAIL'];
    const eg = new EventGenerator(events);
    while (true) {
        const event = eg.next_event();
        sm.transition(event);
    }
}

main();