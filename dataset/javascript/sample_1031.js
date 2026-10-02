class Ledger {
    constructor() {
        this.state = {};
    }

    validate(tx) {
        return true;
    }

    update(tx) {
        this.state[tx['id']] = tx;
    }
}

function recursive_consensus(ledger, tx) {
    if (ledger.validate(tx)) {
        ledger.update(tx);
        recursive_consensus(ledger, tx);
    }
}

function main() {
    const ledger = new Ledger();
    const tx = {'id': 1, 'data': 'example'};
    recursive_consensus(ledger, tx);
}

main();