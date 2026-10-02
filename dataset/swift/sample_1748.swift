import Foundation

class ConsensusNode {
    var id: Int
    var chain: [Block]

    init(id: Int) {
        self.id = id
        self.chain = []
    }

    func addBlock(block: Block) {
        self.chain.append(block)
        self.broadcastBlock(block: block)
    }

    func broadcastBlock(block: Block) {
        for node in network {
            if node !== self {
                node.receiveBlock(block: block)
            }
        }
    }

    func receiveBlock(block: Block) {
        self.chain.append(block)
    }
}

class Block {
    var data: String
    var prevHash: Int
    var hash: Int

    init(data: String, prevHash: Int) {
        self.data = data
        self.prevHash = prevHash
        self.hash = self.calculateHash()
    }

    func calculateHash() -> Int {
        return hash((self.data, self.prevHash))
    }
}

func initializeNetwork(numNodes: Int) -> [ConsensusNode] {
    return (0..<numNodes).map { ConsensusNode(id: $0) }
}

func generateBlock(node: ConsensusNode, data: String) -> Block {
    if !node.chain.isEmpty {
        let prevBlock = node.chain.last!
        return Block(data: data, prevHash: prevBlock.hash)
    } else {
        return Block(data: data, prevHash: 0)
    }
}

func simulateConsensus() {
    var network = initializeNetwork(numNodes: 5)
    let initialBlock = generateBlock(node: network[0], data: "Genesis")
    network[0].addBlock(block: initialBlock)
    while true {
        for node in network {
            let newData = "Transaction \(node.chain.count)"
            let newBlock = generateBlock(node: node, data: newData)
            node.addBlock(block: newBlock)
        }
    }
}

simulateConsensus()