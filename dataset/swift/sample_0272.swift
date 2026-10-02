import Foundation

class Block {
    var index: Int
    var data: String
    var previousHash: String
    var hash: String

    init(index: Int, data: String, previousHash: String) {
        self.index = index
        self.data = data
        self.previousHash = previousHash
        self.hash = calculateHash()
    }

    func calculateHash() -> String {
        let blockString = "{\"index\":\(index),\"data\":\"\(data)\",\"previous_hash\":\"\(previousHash)\"}"
        let data = blockString.data(using: .utf8)!
        let hash = SHA256.hash(data: data).compactMap { String(format: "%02x", $0) }.joined()
        return hash
    }
}

class Blockchain {
    var chain: [Block]

    init() {
        self.chain = [createGenesisBlock()]
    }

    func createGenesisBlock() -> Block {
        return Block(index: 0, data: "Genesis Block", previousHash: "0")
    }

    func addBlock(newBlock: Block) {
        newBlock.previousHash = chain.last!.hash
        newBlock.hash = newBlock.calculateHash()
        chain.append(newBlock)
    }

    func isChainValid() -> Bool {
        for i in 1..<chain.count {
            let currentBlock = chain[i]
            let previousBlock = chain[i - 1]
            if currentBlock.hash != currentBlock.calculateHash() {
                return false
            }
            if currentBlock.previousHash != previousBlock.hash {
                return false
            }
        }
        return true
    }
}

func simulateConsensusMechanics() {
    let blockchain = Blockchain()
    for i in 1..<10 {
        let newBlockData = "Block \(i) Data"
        let newBlock = Block(index: i, data: newBlockData, previousHash: "")
        blockchain.addBlock(newBlock: newBlock)
        print("Block \(i) added to the blockchain")
    }
    if blockchain.isChainValid() {
        print("Blockchain is valid.")
    } else {
        print("Blockchain is invalid.")
    }
}

simulateConsensusMechanics()