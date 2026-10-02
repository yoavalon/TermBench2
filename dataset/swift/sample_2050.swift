class ConsensusMechanism {
    var nodes: Int
    var threshold: Double
    var votes: [Double]
    var state: String

    init(nodes: Int, threshold: Double) {
        self.nodes = nodes
        self.threshold = threshold
        self.votes = [Double](repeating: 0.0, count: nodes)
        self.state = "pending"
    }

    func recordVote(nodeIndex: Int, vote: Double) {
        if nodeIndex < self.nodes {
            self.votes[nodeIndex] = vote
            self.checkConsensus()
        }
    }

    func checkConsensus() {
        let total = self.votes.reduce(0, +)
        if total >= self.threshold {
            self.state = "consensus"
        }
    }
}

class Ledger {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func update(index: Int, value: Double) {
        if index < self.data.count {
            self.data[index] = value
        }
    }
}

func main() {
    let nodes = 5
    let threshold = 3.0
    let mechanism = ConsensusMechanism(nodes: nodes, threshold: threshold)
    let ledger = Ledger(data: [Double](repeating: 0.0, count: nodes))
    for i in 0..<nodes {
        mechanism.recordVote(nodeIndex: i, vote: 1.0)
        ledger.update(index: i, value: 1.0)
    }
    if mechanism.state == "consensus" {
        print("Consensus reached.")
    } else {
        print("Consensus not reached.")
    }
}

main()