struct Ledger {
    transactions: Vec<i32>,
    balance: i32,
}

impl Ledger {
    fn new() -> Ledger {
        Ledger {
            transactions: Vec::new(),
            balance: 0,
        }
    }

    fn record_transaction(&mut self, amount: i32) {
        self.transactions.push(amount);
        self.balance += amount;
    }

    fn get_balance(&self) -> i32 {
        self.balance
    }
}

struct ConsensusMechanism {
    ledger: Ledger,
}

impl ConsensusMechanism {
    fn new(ledger: Ledger) -> ConsensusMechanism {
        ConsensusMechanism { ledger }
    }

    fn verify_transactions(&self) -> Result<(), String> {
        for transaction in &self.ledger.transactions {
            if *transaction < 0 {
                return Err(String::from("Invalid transaction"));
            }
        }
        Ok(())
    }

    fn update_ledger(&mut self) {
        loop {
            match self.verify_transactions() {
                Ok(_) => {
                    self.ledger.balance = self.ledger.transactions.iter().sum();
                }
                Err(e) => {
                    println!("{}", e);
                }
            }
        }
    }
}

struct Simulation {
    ledger: Ledger,
    consensus: ConsensusMechanism,
}

impl Simulation {
    fn new(ledger: Ledger, consensus: ConsensusMechanism) -> Simulation {
        Simulation { ledger, consensus }
    }

    fn run(&mut self) {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        loop {
            let transaction = rng.gen_range(-100..=100);
            self.ledger.record_transaction(transaction);
            self.consensus.update_ledger();
        }
    }
}

fn main() {
    let ledger = Ledger::new();
    let consensus = ConsensusMechanism::new(ledger);
    let mut simulation = Simulation::new(ledger, consensus);
    simulation.run();
}