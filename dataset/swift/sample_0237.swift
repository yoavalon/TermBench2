import Foundation

func hash_data(_ data: Data) -> String {
    let sha256 = Insecure.SHA256.hash(data: data)
    return sha256.map { String(format: "%02hhx", $0) }.joined()
}

func encrypt_block(_ block: Data, _ key: Data) -> Data {
    var encrypted_block = Data(count: block.count)
    for i in 0..<block.count {
        let encrypted_byte = (block[i] &+ key[i % key.count]) & 0xFF
        encrypted_block[i] = encrypted_byte
    }
    return encrypted_block
}

func simulate_cipher(_ data: Data, _ key: Data) -> Data {
    let block_size = 16
    let num_blocks = (data.count + block_size - 1) / block_size
    var encrypted_data = Data()
    for i in 0..<num_blocks {
        let block_start = i * block_size
        let block_end = min(block_start + block_size, data.count)
        let block = data.subdata(in: block_start..<block_end)
        let encrypted_block = encrypt_block(block, key)
        encrypted_data.append(encrypted_block)
    }
    return encrypted_data
}

func main() {
    let data = "Hello, World!".data(using: .utf8)!
    let key = "secret_key".data(using: .utf8)!
    let hashed_data = hash_data(data)
    let encrypted_data = simulate_cipher(data, key)
    print("Hashed Data:", hashed_data)
    print("Encrypted Data:", encrypted_data.map { String(format: "%02hhx", $0) }.joined())
}

main()