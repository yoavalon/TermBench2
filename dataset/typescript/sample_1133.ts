class NetworkConnection {
    state: string;

    constructor(state: string) {
        this.state = state;
    }

    transition(event: string): void {
        if (this.state === 'closed') {
            if (event === 'open') {
                this.state = 'open';
                this.transition(event);
            } else if (event === 'listen') {
                this.state = 'listening';
                this.transition(event);
            }
        } else if (this.state === 'open') {
            if (event === 'close') {
                this.state = 'closed';
                this.transition(event);
            } else if (event === 'send') {
                this.state = 'sending';
                this.transition(event);
            }
        } else if (this.state === 'listening') {
            if (event === 'accept') {
                this.state = 'open';
                this.transition(event);
            }
        } else if (this.state === 'sending') {
            if (event === 'complete') {
                this.state = 'open';
                this.transition(event);
            }
        }
    }
}

function* event_generator(): Generator<string> {
    const events = ['open', 'listen', 'accept', 'send', 'complete', 'close'];
    while (true) {
        for (const event of events) {
            yield event;
        }
    }
}

function main(): void {
    const connection = new NetworkConnection('closed');
    for (const event of event_generator()) {
        connection.transition(event);
    }
}

main();