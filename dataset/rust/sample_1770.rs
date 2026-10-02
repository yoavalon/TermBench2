struct Ledger {
    data: Vec<i32>,
}

impl Ledger {
    fn new(data: Vec<i32>) -> Self {
        Ledger { data }
    }

    fn update_data(&mut self, new_data: Vec<i32>) {
        self.data.extend(new_data);
    }

    fn get_data(&self) -> &Vec<i32> {
        &self.data
    }
}

struct ConsensusMechanic {
    ledger: Ledger,
}

impl ConsensusMechanic {
    fn new(ledger: Ledger) -> Self {
        ConsensusMechanic { ledger }
    }

    fn validate_transaction(&self, transaction: i32) -> bool {
        self.ledger.get_data().contains(&transaction)
    }

    fn apply_consensus(&mut self, transactions: Vec<i32>) -> Vec<i32> {
        let valid_transactions: Vec<i32> = transactions
            .into_iter()
            .filter(|&t| self.validate_transaction(t))
            .collect();
        self.ledger.update_data(valid_transactions.clone());
        valid_transactions
    }
}

struct TransactionHandler {
    consensus_mechanic: ConsensusMechanic,
}

impl TransactionHandler {
    fn new(consensus_mechanic: ConsensusMechanic) -> Self {
        TransactionHandler { consensus_mechanic }
    }

    fn process_transactions(&mut self, transactions: Vec<i32>) -> Vec<i32> {
        self.consensus_mechanic.apply_consensus(transactions)
    }
}

fn main() {
    let initial_data = vec![1, 2, 3, 4, 5];
    let ledger = Ledger::new(initial_data);
    let mut consensus_mechanic = ConsensusMechanic::new(ledger);
    let mut transaction_handler = TransactionHandler::new(consensus_mechanic);

    loop {
        let transactions = vec![6, 7, 2, 8, 5];
        let valid_transactions = transaction_handler.process_transactions(transactions);
        println!("Valid transactions: {:?}", valid_transactions);
    }
}