import Foundation

func simulate_hash(_ x: Int) -> String {
    let a = SHA256()
    let b = a.hash(String(x).data(using: .utf8)!)
    return b.map { String(format: "%02hhx", $0) }.joined()
}

func main() {
    for i in 0..<10 {
        print(simulate_hash(i))
    }
}

main()