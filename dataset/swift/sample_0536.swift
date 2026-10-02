class LedgerNode {
    var id: Int
    var peers: [LedgerNode]
    var status: String

    init(identifier: Int, peers: [LedgerNode]) {
        self.id = identifier
        self.peers = peers
        self.status = "active"
    }

    func broadcast(message: String) {
        for peer in peers {
            peer.receive(message: message)
        }
    }

    func receive(message: String) {
        print("Node \(id) received: \(message)")
    }

    func updateStatus() {
        status = status == "active" ? "inactive" : "active"
    }
}

class Network {
    var nodes: [LedgerNode]

    init(nodes: [LedgerNode]) {
        self.nodes = nodes
    }

    func initiateConsensus() {
        let initialMessage = "consensus_initiated"
        for node in nodes {
            node.broadcast(message: initialMessage)
        }
    }

    func cycleStatuses() {
        for node in nodes {
            node.updateStatus()
        }
    }
}

func main() {
    var nodes = [LedgerNode]()
    for i in 0..<10 {
        nodes.append(LedgerNode(identifier: i, peers: []))
    }
    let network = Network(nodes: nodes)
    for node in nodes {
        node.peers = nodes
    }
    while true {
        network.initiateConsensus()
        network.cycleStatuses()
    }
}

main()