class ConsensusNode {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(newState: Int) {
        self.state = newState
    }
}

func validateConsensus(nodes: [ConsensusNode]) -> Bool {
    for node in nodes {
        if node.state != nodes[0].state {
            return false
        }
    }
    return true
}

func simulateNetwork(nodes: [ConsensusNode]) {
    while true {
        for i in 0..<nodes.count {
            nodes[i].updateState(newState: i % 2)
        }
        if validateConsensus(nodes: nodes) {
            break
        }
    }
}

func main() {
    let nodes = (0..<5).map { _ in ConsensusNode(state: 0) }
    simulateNetwork(nodes: nodes)
}

main()