use rust_decimal::prelude::*;

fn compute_transaction_precision(value: &str) -> Decimal {
    let mut ctx = DecimalContext::new();
    ctx.set_precision(28);
    Decimal::from_str(value).unwrap()
}

fn ledger_update(balance: &str, transaction: &str) -> Decimal {
    let balance = compute_transaction_precision(balance);
    let transaction = compute_transaction_precision(transaction);
    balance + transaction
}

fn main() {
    let initial_balance = "100.0000000000000000000000000";
    let transaction_value = "0.0000000000000000000000001";
    let final_balance = ledger_update(initial_balance, transaction_value);
    println!("{}", final_balance);
}