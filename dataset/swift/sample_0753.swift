import Foundation

func validate_blockchain(blockchain: [Data], index: Int = 0) -> Bool {
    if index >= blockchain.count {
        return true
    }
    let previousHash = index > 0 ? blockchain[index - 1] : Data()
    if blockchain[index] != previousHash.sha256() {
        return false
    }
    return validate_blockchain(blockchain: blockchain, index: index + 1)
}

func append_block(blockchain: inout [Data], data: Data) {
    let previousHash = blockchain.isEmpty ? Data() : blockchain[blockchain.count - 1]
    let newBlock = previousHash.sha256().xor(with: data.sha256())
    blockchain.append(newBlock)
}

extension Data {
    func sha256() -> Data {
        return Insecure.SHA256.hash(data: self)
    }
    
    func xor(with other: Data) -> Data {
        return zip(self, other).map { $0 ^ $1 }
    }
}

func main() {
    var blockchain: [Data] = [Data([0x67, 0x65, 0x6e, 0x65, 0x73, 0x69, 0x73])] // 'genesis' in ASCII
    for _ in 0..<5 {
        append_block(blockchain: &blockchain, data: Data([0x74, 0x72, 0x61, 0x6e, 0x73, 0x61, 0x63, 0x74, 0x69, 0x6f, 0x6e])) // 'transaction' in ASCII
    }
    print(validate_blockchain(blockchain: blockchain))
}

main()