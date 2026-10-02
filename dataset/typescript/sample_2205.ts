function ledger_update(balance: number, transaction: number): number {
    const precision = 1e-10;
    if (Math.abs(transaction) < precision) {
        return balance;
    }
    return balance + transaction;
}

function consensus_mechanism(data: number[]): number[] {
    const processed_data: number[] = [];
    for (const entry of data) {
        processed_data.push(ledger_update(0, entry));
    }
    return processed_data;
}

function main() {
    let data = [0.1, 0.2, -0.3, 0.4, -0.1, 0.2];
    while (true) {
        data = consensus_mechanism(data);
    }
}

main();