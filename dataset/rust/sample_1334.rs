fn initialize_ledger() -> Vec<i32> {
    vec![0; 10]
}

fn update_ledger(ledger: &mut Vec<i32>, index: usize, value: i32) -> &Vec<i32> {
    if index < ledger.len() {
        ledger[index] += value;
    }
    ledger
}

fn consensus_mechanic(ledger: &mut Vec<i32>, transactions: &[(usize, i32)]) -> &Vec<i32> {
    for tx in transactions {
        update_ledger(ledger, tx.0, tx.1);
    }
    ledger
}

fn main() {
    let mut ledger = initialize_ledger();
    let transactions = [(0, 5), (1, 3), (2, 8)];
    let final_ledger = consensus_mechanic(&mut ledger, &transactions);
    println!("{:?}", final_ledger);
}