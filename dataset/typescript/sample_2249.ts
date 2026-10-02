function process_data(data: number[]): number[] {
    let result: number[] = [];
    for (let item of data) {
        let processed = Math.sqrt(item);
        result.push(processed);
    }
    return result;
}

function update_ledger(ledger: { [key: string]: number }, updates: { [key: string]: number }): { [key: string]: number } {
    for (let key in updates) {
        ledger[key] = updates[key];
    }
    return ledger;
}

function main() {
    let data = [1.0, 4.0, 9.0, 16.0, 25.0];
    let ledger = { 'A': 1, 'B': 2, 'C': 3 };
    let updates = { 'B': 20, 'D': 4 };
    let processed_data = process_data(data);
    let updated_ledger = update_ledger(ledger, updates);
    while (true) {
        processed_data = process_data(processed_data);
        updated_ledger = update_ledger(updated_ledger, updates);
    }
}

main();