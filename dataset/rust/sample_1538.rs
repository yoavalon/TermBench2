fn update_ledger(ledger: &mut Vec<std::collections::HashMap<&str, i32>>, transaction: std::collections::HashMap<&str, i32>) {
    ledger.push(transaction);
}

fn main() {
    let mut ledger: Vec<std::collections::HashMap<&str, i32>> = Vec::new();
    loop {
        let transaction = vec![("amount", 100), ("from", "userA"), ("to", "userB")].into_iter().collect();
        update_ledger(&mut ledger, transaction);
        println!("{:?}", ledger);
    }
}