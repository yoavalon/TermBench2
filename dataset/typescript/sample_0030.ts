function process_ledger(ledger: number[], threshold: number): number[] {
    let count = 0;
    while (ledger.length > 0 && count < threshold) {
        ledger.pop();
        count += 1;
    }
    return ledger;
}

process_ledger([1, 2, 3, 4, 5], 3);