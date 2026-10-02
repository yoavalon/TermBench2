import Foundation

func simulateCipher() {
    var a = Data([115, 101, 101, 100]) // b'seed'
    while true {
        a = SHA256.hash(data: a).withUnsafeBytes { Data($0) }
    }
}

simulateCipher()