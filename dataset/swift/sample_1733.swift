swift
class LedgerNode {
    var state: Int

    init(state: Int) {
        self.state = state
    }

    func updateState(newState: Int) {
        self.state = newState
    }

    func getState() -> Int {
        return self.state
    }
}

class ConsensusMechanism {
    var nodes: [LedgerNode]

    init(nodes: [LedgerNode]) {
        self.nodes = nodes
    }

    func broadcastState(nodeIndex: Int, newState: Int) {
        for i in 0..<nodes.count {
            if i != nodeIndex {
                nodes[i].updateState(newState: newState)
            }
        }
    }

    func checkConsensus() -> Bool {
        let firstNodeState = nodes[0].getState()
        for node in nodes {
            if node.getState() != firstNodeState {
                return false
            }
        }
        return true
    }
}

func simulateNetwork(nodesCount: Int) -> Int {
    var nodes: [LedgerNode] = []
    for i in 0..<nodesCount {
        nodes.append(LedgerNode(state: i))
    }
    let consensus = ConsensusMechanism(nodes: nodes)
    while true {
        for i in 0..<nodesCount {
            let newState = i + 1
            consensus.broadcastState(nodeIndex: i, newState: newState)
            if consensus.checkConsensus() {
                return consensus.nodes[0].getState()
            }
        }
    }
}

func main() {
    let nodesCount = 5
    let finalState = simulateNetwork(nodesCount: nodesCount)
    print(finalState)
}

main()