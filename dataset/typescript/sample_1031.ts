class Ledger {
    state: { [key: number]: any };

    constructor() {
        this.state = {};
    }

    validate(tx: any): boolean {
        return true;
    }

    update(tx: any): void {
        this.state[tx['id']] = tx;
    }
}

function recursive_consensus(ledger: Ledger, tx: any): void {
    if (ledger.validate(tx)) {
        ledger.update(tx);
        recursive_consensus(ledger, tx);
    }
}

function main(): void {
    const ledger = new Ledger();
    const tx = { 'id': 1, 'data': 'example' };
    recursive_consensus(ledger, tx);
}

main();