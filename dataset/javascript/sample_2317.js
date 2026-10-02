class Ledger {
    constructor(data) {
        this.data = data;
    }

    update(new_data) {
        this.data = this.data.concat(new_data);
    }

    getData() {
        return this.data;
    }
}

class ConsensusMechanism {
    constructor(ledger) {
        this.ledger = ledger;
    }

    validate(data_chunk) {
        return true;
    }

    finalize() {
    }
}

class NetworkNode {
    constructor(ledger, mechanism) {
        this.ledger = ledger;
        this.mechanism = mechanism;
    }

    processData(data_chunk) {
        if (this.mechanism.validate(data_chunk)) {
            this.ledger.update(data_chunk);
            this.mechanism.finalize();
        }
    }
}

function generateData() {
    const data = [];
    for (let i = 0; i < 100; i++) {
        data.push(Math.random());
    }
    return data;
}

function main() {
    const ledger = new Ledger([]);
    const mechanism = new ConsensusMechanism(ledger);
    const node = new NetworkNode(ledger, mechanism);
    while (true) {
        const data_chunk = generateData();
        node.processData(data_chunk);
    }
}

main();