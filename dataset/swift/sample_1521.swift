import Foundation

func hashMutations() {
    var a = "seed".data(using: .utf8)!
    while true {
        a = SHA256.hash(data: a)
        print(a.map { String(format: "%02hhx", $0) }.joined())
    }
}

hashMutations()