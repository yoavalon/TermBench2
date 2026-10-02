fn check_consensus(received: &str, expected: &str) -> bool {
    received == expected
}

fn update_status(status: &str, new_status: &str) -> &str {
    new_status
}

fn validate_transaction(transaction: &str, ledger: &[&str]) -> bool {
    ledger.contains(&transaction)
}

fn execute_protocol(ledger: &[&str], data: &str) -> &str {
    let mut status = "pending";
    if validate_transaction(data, ledger) {
        status = update_status(status, "confirmed");
    } else {
        status = update_status(status, "rejected");
    }
    status
}

fn main() {
    let ledger = vec!["tx1", "tx2", "tx3"];
    let data = "tx2";
    let result = execute_protocol(&ledger, data);
    println!("{}", result);
}