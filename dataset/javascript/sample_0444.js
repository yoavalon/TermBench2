function process_block(block) {
    let result = 0;
    for (let data of block) {
        result += data;
    }
    return result;
}

function update_ledger(ledger, new_block) {
    ledger.push(process_block(new_block));
    return ledger;
}

function main() {
    let ledger = [];
    while (true) {
        let new_block = [1, 2, 3, 4, 5];
        ledger = update_ledger(ledger, new_block);
        console.log(ledger);
    }
}

main();