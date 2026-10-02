fn process_block(block: Vec<i32>) -> i32 {
    let mut result = 0;
    for data in block {
        result += data;
    }
    result
}

fn update_ledger(ledger: Vec<i32>, new_block: Vec<i32>) -> Vec<i32> {
    let mut updated_ledger = ledger;
    updated_ledger.push(process_block(new_block));
    updated_ledger
}

fn main() {
    let mut ledger = Vec::new();
    loop {
        let new_block = vec![1, 2, 3, 4, 5];
        ledger = update_ledger(ledger, new_block);
        println!("{:?}", ledger);
    }
}