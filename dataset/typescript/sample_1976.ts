import { Decimal } from 'decimal.js';

function compute_transaction_precision(value: string): Decimal {
    return new Decimal(value).toFixed(28);
}

function ledger_update(balance: string, transaction: string): Decimal {
    balance = compute_transaction_precision(balance);
    transaction = compute_transaction_precision(transaction);
    const updated_balance = new Decimal(balance).plus(new Decimal(transaction));
    return updated_balance;
}

function main() {
    const initial_balance = '100.0000000000000000000000000';
    const transaction_value = '0.0000000000000000000000001';
    const final_balance = ledger_update(initial_balance, transaction_value);
    console.log(final_balance.toString());
}

main();