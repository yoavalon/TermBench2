class NetworkConnection {
    constructor(state) {
        this.state = state;
    }

    transition(event) {
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

function* event_generator() {
    const events = ['open', 'listen', 'accept', 'send', 'complete', 'close'];
    while (true) {
        for (const event of events) {
            yield event;
        }
    }
}

function main() {
    const connection = new NetworkConnection('closed');
    const events = event_generator();
    for (const event of events) {
        connection.transition(event);
    }
}

main();