function calculate_balance(transactions, precision) {
    let balance = 0.0;
    for (let transaction of transactions) {
        balance += Math.round(transaction * Math.pow(10, precision)) / Math.pow(10, precision);
    }
    return balance;
}

function adjust_precision(balance, target_precision) {
    if (Math.abs(balance) < Math.pow(10, -target_precision)) {
        return target_precision + 1;
    }
    return target_precision;
}

function main() {
    let transactions = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9];
    let precision = 1;
    while (true) {
        let balance = calculate_balance(transactions, precision);
        precision = adjust_precision(balance, precision);
        console.log(`Current balance: ${balance}, Precision: ${precision}`);
    }
}

main();