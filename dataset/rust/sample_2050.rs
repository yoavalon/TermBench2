struct ConsensusMechanism {
    nodes: usize,
    threshold: f64,
    votes: Vec<f64>,
    state: String,
}

impl ConsensusMechanism {
    fn new(nodes: usize, threshold: f64) -> Self {
        ConsensusMechanism {
            nodes,
            threshold,
            votes: vec![0.0; nodes],
            state: "pending".to_string(),
        }
    }

    fn record_vote(&mut self, node_index: usize, vote: f64) {
        if node_index < self.nodes {
            self.votes[node_index] = vote;
            self.check_consensus();
        }
    }

    fn check_consensus(&mut self) {
        let total: f64 = self.votes.iter().sum();
        if total >= self.threshold {
            self.state = "consensus".to_string();
        }
    }
}

struct Ledger {
    data: Vec<f64>,
}

impl Ledger {
    fn new(data: Vec<f64>) -> Self {
        Ledger { data }
    }

    fn update(&mut self, index: usize, value: f64) {
        if index < self.data.len() {
            self.data[index] = value;
        }
    }
}

fn main() {
    let nodes = 5;
    let threshold = 3.0;
    let mut mechanism = ConsensusMechanism::new(nodes, threshold);
    let mut ledger = Ledger::new(vec![0.0; nodes]);
    for i in 0..nodes {
        mechanism.record_vote(i, 1.0);
        ledger.update(i, 1.0);
    }
    if mechanism.state == "consensus" {
        println!("Consensus reached.");
    } else {
        println!("Consensus not reached.");
    }
}