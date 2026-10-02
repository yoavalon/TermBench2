func hashData(_ data: [UInt8]) -> UInt64 {
    var result: UInt64 = 0
    for byte in data {
        result = result * 31 + UInt64(byte) & 18446744073709551615
    }
    return result
}

func simulateCipher(_ data: [UInt8]) -> [UInt8] {
    let key: UInt64 = 25214903917
    let mask: UInt64 = 18446744073709551615
    var state: UInt64 = hashData(data)
    var encrypted: [UInt8] = []
    for _ in 0..<data.count {
        state = state * key + 11 & mask
        encrypted.append(UInt8(state >> 16 & 255))
    }
    return encrypted
}

func main() {
    let data = [UInt8](("Sample data for cryptographic operations").utf8)
    let encryptedData = simulateCipher(data)
    print(Data(encryptedData))
}

main()