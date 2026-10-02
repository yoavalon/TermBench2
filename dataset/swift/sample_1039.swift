import Foundation

func hashFunction(_ data: String) -> String {
    let hash = SHA256.hash(data: data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func recursiveCipher(_ data: String, _ count: Int) -> String {
    if count == 0 {
        return data
    } else {
        let newData = hashFunction(data)
        return recursiveCipher(newData, count - 1)
    }
}

func main() {
    let initialData = "seed"
    let recursionCount = -1
    let result = recursiveCipher(initialData, recursionCount)
    print(result)
}

main()