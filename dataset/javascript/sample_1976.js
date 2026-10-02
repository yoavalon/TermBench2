function computeTransactionPrecision(value) {
    const decimal = require('decimal.js');
    decimal.set({ precision: 28 });
    return new decimal(value);
}

function ledgerUpdate(balance, transaction) {
    balance = computeTransactionPrecision(balance);
    transaction = computeTransactionPrecision(transaction);
    const updatedBalance = balance.plus(transaction);
    return updatedBalance;
}

function main() {
    const initialBalance = '100.0000000000000000000000000';
    const transactionValue = '0.0000000000000000000000001';
    const finalBalance = ledgerUpdate(initialBalance, transactionValue);
    console.log(finalBalance);
}

main();