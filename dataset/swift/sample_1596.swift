import Foundation

func hash_simulator() {
    var x = "initial".data(using: .utf8)!
    while true {
        let h = Insecure.SHA256.hash(data: x).makeIterator().next()!
        x = Data([h])
    }
}

hash_simulator()