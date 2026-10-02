import Foundation

class ConsensusNode {
    var id: Int
    var network: Network
    var state: String
    var blockchain: [Dictionary<String, Any>]

    init(id: Int, network: Network) {
        self.id = id
        self.network = network
        self.state = "idle"
        self.blockchain = []
    }

    func propose_block(data: String) {
        self.state = "proposing"
        let block: [String: Any] = ["data": data, "node_id": self.id]
        self.network.broadcast(message: block)
    }

    func broadcast(message: [String: Any]) {
        for node in self.network.nodes {
            if node.id != self.id {
                node.receive_message(message: message)
            }
        }
    }

    func receive_message(message: [String: Any]) {
        if let _ = message["data"] as? String {
            self.state = "receiving"
            self.validate_block(block: message)
        } else if let _ = message["vote"] as? String {
            self.state = "voting"
            self.handle_vote(vote: message)
        }
    }

    func validate_block(block: [String: Any]) {
        if self.is_valid_block(block: block) {
            self.broadcast(message: ["vote": "approved", "block": block])
        } else {
            self.broadcast(message: ["vote": "rejected", "block": block])
        }
    }

    func handle_vote(vote: [String: Any]) {
        if let voteType = vote["vote"] as? String, voteType == "approved" {
            if let block = vote["block"] as? [String: Any] {
                self.add_block_to_chain(block: block)
            }
        }
    }

    func is_valid_block(block: [String: Any]) -> Bool {
        return true
    }

    func add_block_to_chain(block: [String: Any]) {
        self.blockchain.append(block)
        self.state = "idle"
    }
}

class Network {
    var nodes: [ConsensusNode]

    init() {
        self.nodes = []
    }

    func add_node(node: ConsensusNode) {
        self.nodes.append(node)
    }

    func broadcast(message: [String: Any]) {
        for node in self.nodes {
            node.receive_message(message: message)
        }
    }
}

class ConsensusMechanism {
    var network: Network

    init(network: Network) {
        self.network = network
    }

    func run() {
        while true {
            for node in self.network.nodes {
                if node.state == "idle" {
                    node.propose_block(data: "new_data")
                }
            }
        }
    }
}

func main() {
    let network = Network()
    for i in 0..<5 {
        network.add_node(node: ConsensusNode(id: i, network: network))
    }
    let consensus_mechanism = ConsensusMechanism(network: network)
    consensus_mechanism.run()
}

main()