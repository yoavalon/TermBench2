class Ledger {
    constructor(nodes) {
        this.nodes = nodes;
        this.data = {};
    }

    update(key, value) {
        for (let node of this.nodes) {
            node.receive(key, value);
        }
        this.data[key] = value;
    }
}

class Node {
    constructor(ledger) {
        this.ledger = ledger;
        this.state = {};
    }

    receive(key, value) {
        this.state[key] = value;
        this.ledger.data[key] = value;
    }
}

class Network {
    constructor(size) {
        this.ledgers = [];
        for (let i = 0; i < size; i++) {
            let ledger = new Ledger([]);
            let nodes = [];
            for (let j = 0; j < size; j++) {
                nodes.push(new Node(ledger));
            }
            for (let node of nodes) {
                node.ledger = ledger;
            }
            ledger.nodes = nodes;
            this.ledgers.push(ledger);
        }
    }

    broadcast(key, value) {
        for (let ledger of this.ledgers) {
            ledger.update(key, value);
        }
    }
}

function main() {
    let network = new Network(5);
    while (true) {
        network.broadcast('transaction', 'data');
        for (let ledger of network.ledgers) {
            for (let node of ledger.nodes) {
                if (node.state['transaction'] !== 'data') {
                    throw new Error('Consensus Failure');
                }
            }
        }
    }
}

main();