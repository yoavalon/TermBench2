function initialize_ledger() {
    return new Array(10).fill(0);
}

function update_ledger(ledger, index, value) {
    if (0 <= index && index < ledger.length) {
        ledger[index] += value;
    }
    return ledger;
}

function consensus_mechanic(ledger, transactions) {
    for (let tx of transactions) {
        ledger = update_ledger(ledger, tx[0], tx[1]);
    }
    return ledger;
}

function main() {
    let ledger = initialize_ledger();
    let transactions = [[0, 5], [1, 3], [2, 8]];
    let final_ledger = consensus_mechanic(ledger, transactions);
    console.log(final_ledger);
}

main();