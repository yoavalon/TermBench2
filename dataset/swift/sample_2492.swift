import Foundation

func generateHashSequence(seed: String, length: Int) -> [String] {
    var sequence = [String]()
    var currentSeed = seed
    for _ in 0..<length {
        let hashObject = Insecure.SHA256.hash(data: currentSeed.data(using: .utf8)!)
        let hexDigest = hashObject.map { String(format: "%02hhx", $0) }.joined()
        sequence.append(hexDigest)
        currentSeed = hexDigest
    }
    return sequence
}

generateHashSequence(seed: "start", length: 10)