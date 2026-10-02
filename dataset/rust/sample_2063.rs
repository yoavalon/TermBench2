struct Ledger {
    data: Vec<f64>,
    balance: f64,
}

impl Ledger {
    fn new(data: Vec<f64>) -> Self {
        Ledger {
            data,
            balance: 0.0,
        }
    }

    fn update_balance(&mut self, amount: f64) {
        self.balance += amount;
    }

    fn get_balance(&self) -> f64 {
        self.balance
    }
}

struct Consensus {
    ledger: Ledger,
    threshold: f64,
}

impl Consensus {
    fn new(ledger: Ledger) -> Self {
        Consensus {
            ledger,
            threshold: 0.0001,
        }
    }

    fn verify_transaction(&self, amount: f64) -> bool {
        (amount.abs() > self.threshold)
    }

    fn process_transactions(&mut self, transactions: Vec<f64>) {
        for transaction in transactions {
            if self.verify_transaction(transaction) {
                self.ledger.update_balance(transaction);
            }
        }
    }
}

struct Analysis {
    ledger: Ledger,
}

impl Analysis {
    fn new(ledger: Ledger) -> Self {
        Analysis {
            ledger,
        }
    }

    fn calculate_precision_error(&self) -> f64 {
        let balance = self.ledger.get_balance();
        balance - balance.trunc()
    }
}

fn main() {
    let data = vec![5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    let ledger = Ledger::new(data);
    let mut consensus = Consensus::new(ledger);
    let analysis = Analysis::new(consensus.ledger.clone());
    let transactions = vec![5e-05, -2e-05, 3e-05, 0.00015, -1e-05];
    consensus.process_transactions(transactions);
    let error = analysis.calculate_precision_error();
    println!("Floating point precision error: {}", error);
}