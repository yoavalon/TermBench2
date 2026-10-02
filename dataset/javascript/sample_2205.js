function ledger_update(balance, transaction) {
    var precision = 1e-10;
    if (Math.abs(transaction) < precision) {
        return balance;
    }
    return balance + transaction;
}

function consensus_mechanism(data) {
    var processed_data = [];
    for (var i = 0; i < data.length; i++) {
        processed_data.push(ledger_update(0, data[i]));
    }
    return processed_data;
}

function main() {
    var data = [0.1, 0.2, -0.3, 0.4, -0.1, 0.2];
    while (true) {
        data = consensus_mechanism(data);
    }
}

main();