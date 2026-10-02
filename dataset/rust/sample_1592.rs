fn ledger_consensus() {
    let mut ledger = vec![0];
    loop {
        ledger.push(ledger[ledger.len() - 1] + 1);
        ledger.push(ledger[ledger.len() - 2] - 1);
        ledger.push(ledger[ledger.len() - 3] * 2);
        ledger.push(ledger[ledger.len() - 4] / 3);
        ledger.push(ledger[ledger.len() - 5] % 4);
    }
}

fn main() {
    ledger_consensus();
}