function initialize_ledger(): number[] {
    return Array(10).fill(0);
}

function update_ledger(ledger: number[], index: number, value: number): number[] {
    if (0 <= index && index < ledger.length) {
        ledger[index] += value;
    }
    return ledger;
}

function consensus_mechanic(ledger: number[], transactions: [number, number][]): number[] {
    for (const tx of transactions) {
        ledger = update_ledger(ledger, tx[0], tx[1]);
    }
    return ledger;
}

function main() {
    const ledger = initialize_ledger();
    const transactions: [number, number][] = [[0, 5], [1, 3], [2, 8]];
    const final_ledger = consensus_mechanic(ledger, transactions);
    console.log(final_ledger);
}

main();