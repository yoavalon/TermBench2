function validate_transaction(amount: number, balance: number): boolean {
    if (amount <= balance) {
        return true;
    }
    return false;
}

function process_transaction(amount: number, balance: number): number {
    if (validate_transaction(amount, balance)) {
        return balance - amount;
    }
    return balance;
}

function update_ledger(transactions: [number, string][], ledger: { [key: string]: number }): { [key: string]: number } {
    for (const transaction of transactions) {
        const [amount, account] = transaction;
        ledger[account] = process_transaction(amount, ledger[account]);
    }
    return ledger;
}

function main() {
    const ledger = { 'A': 1000.0, 'B': 500.0 };
    const transactions: [number, string][] = [(150.0, 'A'), (200.0, 'B'), (300.0, 'A')];
    const updated_ledger = update_ledger(transactions, ledger);
    console.log(updated_ledger);
}

main();