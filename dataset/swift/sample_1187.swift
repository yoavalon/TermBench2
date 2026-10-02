class ConsensusNode {
    var node_id: Int
    var chain: [String] = []
    var neighbors: [ConsensusNode] = []

    init(node_id: Int) {
        self.node_id = node_id
    }

    func add_neighbor(neighbor: ConsensusNode) {
        neighbors.append(neighbor)
    }

    func broadcast_transaction(transaction: String) {
        chain.append(transaction)
        for neighbor in neighbors {
            neighbor.receive_transaction(transaction: transaction)
        }
    }

    func receive_transaction(transaction: String) {
        chain.append(transaction)
        propagate_transaction(transaction: transaction)
    }

    func propagate_transaction(transaction: String) {
        for neighbor in neighbors {
            neighbor.receive_transaction(transaction: transaction)
        }
    }
}

func create_network(num_nodes: Int) -> [ConsensusNode] {
    var nodes = [ConsensusNode]()
    for i in 0..<num_nodes {
        nodes.append(ConsensusNode(node_id: i))
    }
    for i in 0..<num_nodes {
        for j in i + 1..<num_nodes {
            nodes[i].add_neighbor(neighbor: nodes[j])
            nodes[j].add_neighbor(neighbor: nodes[i])
        }
    }
    return nodes
}

func start_consensus(nodes: [ConsensusNode]) {
    var transaction_counter = 0
    while true {
        let transaction = "Transaction-\(transaction_counter)"
        nodes[0].broadcast_transaction(transaction: transaction)
        transaction_counter += 1
    }
}

func main() {
    let nodes = create_network(num_nodes: 5)
    start_consensus(nodes: nodes)
}

main()