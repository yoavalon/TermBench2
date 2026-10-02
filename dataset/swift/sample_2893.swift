import Foundation

func hashSequence(seed: String, iterations: Int) -> AnyIterator<String> {
    var x = seed
    return AnyIterator {
        x = Data(x.utf8).withUnsafeBytes { buffer in
            SHA256.hash(data: buffer).map { String(format: "%02hhx", $0) }.joined()
        }
        return x
    }
}

func cipherSimulation(seed: String, iterations: Int) -> AnyIterator<String> {
    let hashGenerator = hashSequence(seed: seed, iterations: iterations)
    return AnyIterator {
        if let h = hashGenerator.next() {
            let md5 = Insecure.MD5.hash(data: Data(h.utf8)).map { String(format: "%02hhx", $0) }.joined()
            return md5
        }
        return nil
    }
}

func main() {
    let seed = "start"
    let iterations = 1000
    var i = 0
    for c in cipherSimulation(seed: seed, iterations: iterations) {
        print("Iteration \(i): \(c)")
        i += 1
    }
}

main()