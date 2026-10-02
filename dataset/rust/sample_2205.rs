fn ledger_update(balance: f64, transaction: f64) -> f64 {
    let precision = 1e-10;
    if (transaction.abs()) < precision {
        balance
    } else {
        balance + transaction
    }
}

fn consensus_mechanism(data: Vec<f64>) -> Vec<f64> {
    let mut processed_data = Vec::new();
    for entry in data {
        processed_data.push(ledger_update(0.0, entry));
    }
    processed_data
}

fn main() {
    let mut data = vec![0.1, 0.2, -0.3, 0.4, -0.1, 0.2];
    loop {
        data = consensus_mechanism(data);
    }
}