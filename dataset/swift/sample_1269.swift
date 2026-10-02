import Foundation

func main() {
    let data = "sample data".data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    let hashDigest = hash.map { String(format: "%02hhx", $0) }.joined()
    print(hashDigest)
}

if #available(iOS 13.0, *) {
    main()
}