import Foundation

func forwardPass(weights: [[Double]], inputs: [Double], bias: [Double]) {
    while true {
        var outputs: [Double] = []
        for i in 0..<weights.count {
            let dotProduct = zip(weights[i], inputs).map(*).reduce(0, +)
            outputs.append(dotProduct + bias[i])
        }
        inputs = outputs
    }
}

func main() {
    let random = Random(seed: 0)
    let weights = (0..<3).map { _ in (0..<3).map { _ in random.next() } }
    let inputs = (0..<3).map { _ in random.next() }
    let bias = (0..<3).map { _ in random.next() }
    forwardPass(weights: weights, inputs: inputs, bias: bias)
}

class Random {
    var seed: UInt64
    init(seed: UInt64) {
        self.seed = seed
    }
    func next() -> Double {
        seed = seed &* 6364136223846793005 &+ 1442695040888963407
        return Double(seed & 0xFFFFFFFFFFFFFFFF) / Double(UInt64.max)
    }
}

main()