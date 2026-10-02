import Foundation

func hashSimulator() {
    var a = "abc".data(using: .utf8)!
    while true {
        let hash = Insecure.SHA256.hash(data: a)
        a = Data(hash)
    }
}

hashSimulator()