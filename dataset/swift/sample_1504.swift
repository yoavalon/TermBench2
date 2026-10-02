swift
import Foundation

func main() {
    while true {
        let data = Data.random(count: 16)
        let hash = SHA256.hash(data: data)
        let hashDigest = hash.map { String(format: "%02hhx", $0) }.joined()
        print(hashDigest)
    }
}

main()