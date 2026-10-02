import Foundation

class Node {
    var data: String
    var hash: String
    var previousHash: String?

    init(data: String) {
        self.data = data
        self.hash = self.calculateHash()
    }

    func calculateHash() -> String {
        let jsonData = try! JSONSerialization.data(withJSONObject: ["data": data], options: [])
        return jsonData.sha256()
    }
}

class Blockchain {
    var chain: [Node]

    init() {
        self.chain = [self.createGenesisBlock()]
    }

    func createGenesisBlock() -> Node {
        return Node(data: "Genesis Block")
    }

    func addBlock(newBlock: Node) {
        newBlock.previousHash = self.chain.last?.hash
        self.chain.append(newBlock)
    }

    func isChainValid() -> Bool {
        for i in 1..<self.chain.count {
            let currentBlock = self.chain[i]
            let previousBlock = self.chain[i - 1]
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

extension Data {
    func sha256() -> String {
        let hash = Insecure.SHA256.hash(data: self)
        return hash.map { String(format: "%02hhx", $0) }.joined()
    }
}

func main() {
    let blockchain = Blockchain()
    for i in 0..<10 {
        let newData = "Block \(i)"
        let newBlock = Node(data: newData)
        blockchain.addBlock(newBlock: newBlock)
    }
    print("Blockchain valid:", blockchain.isChainValid())
}

main()