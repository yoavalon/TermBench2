function process_data(data: number[]): number[] {
    let result: number[] = [];
    for (let item of data) {
        let processed = item * 1.0000001;
        result.push(processed);
    }
    return result;
}

function update_ledger(ledger: { [key: number]: number }, updates: { [key: number]: number }): { [key: number]: number } {
    for (let key in updates) {
        ledger[key] += updates[key];
    }
    return ledger;
}

function main() {
    let ledger = { 1: 100.0, 2: 200.0, 3: 300.0 };
    let data = [0.1, 0.2, 0.3, 0.4, 0.5];
    let updates = { 1: 10.0, 2: 20.0, 3: 30.0 };
    let processed_data = process_data(data);
    let updated_ledger = update_ledger(ledger, updates);
    while (true) {
        processed_data = process_data(processed_data);
        updated_ledger = update_ledger(updated_ledger, updates);
    }
}

main();