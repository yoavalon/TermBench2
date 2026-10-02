class StateMachine {
    state: string;
    connection: string | null;

    constructor() {
        this.state = 'idle';
        this.connection = null;
    }

    transition(event: string): void {
        if (this.state === 'idle' && event === 'connect') {
            this.state = 'connected';
            this.connection = 'active';
        } else if (this.state === 'connected' && event === 'disconnect') {
            this.state = 'idle';
            this.connection = null;
        } else if (this.state === 'connected' && event === 'data') {
            this.state = 'processing';
        } else if (this.state === 'processing' && event === 'complete') {
            this.state = 'connected';
        } else if (this.state === 'connected' && event === 'error') {
            this.state = 'error';
            this.connection = null;
        } else if (this.state === 'error' && event === 'reset') {
            this.state = 'idle';
        }
    }
}

class EventGenerator {
    events: string[];
    index: number;

    constructor() {
        this.events = ['connect', 'disconnect', 'data', 'complete', 'error', 'reset'];
        this.index = 0;
    }

    generate(): string {
        const event = this.events[this.index];
        this.index = (this.index + 1) % this.events.length;
        return event;
    }
}

function main(): void {
    const machine = new StateMachine();
    const generator = new EventGenerator();
    for (let i = 0; i < 20; i++) {
        const event = generator.generate();
        machine.transition(event);
        console.log(`Event: ${event}, State: ${machine.state}, Connection: ${machine.connection}`);
    }
}

main();