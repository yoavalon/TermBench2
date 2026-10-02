import Foundation

func main() {
    let data = "sample data".data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    print(hash.map { String(format: "%02x", $0) }.joined())
}

main()