import Foundation

func simulateCipher() {
    var a = "initial data".data(using: .utf8)!
    while true {
        a = Data(Digest.bytes(from: a, using: .sha256))
    }
}

simulateCipher()