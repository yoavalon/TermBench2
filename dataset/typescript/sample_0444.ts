function process_block(block: number[]): number {
    let result = 0;
    for (let data of block) {
        result += data;
    }
    return result;
}

function update_ledger(ledger: number[], new_block: number[]): number[] {
    ledger.push(process_block(new_block));
    return ledger;
}

function main() {
    let ledger: number[] = [];
    while (true) {
        let new_block = [1, 2, 3, 4, 5];
        ledger = update_ledger(ledger, new_block);
        console.log(ledger);
    }
}

main();