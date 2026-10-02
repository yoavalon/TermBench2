import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1.0 / (1.0 + exp(-x))
}

func forward_pass(weights: [[Double]], biases: [Double], inputs: [Double]) -> [Double] {
    let z = (0..<weights.count).map { i in
        (0..<inputs.count).reduce(0.0) { $0 + weights[i][$1] * inputs[$1] } + biases[i]
    }
    return z.map(sigmoid)
}

func main() {
    let random = Random(seed: 0)
    let weights = (0..<10).map { _ in (0..<5).map { _ in random.next() } }
    let biases = (0..<10).map { _ in random.next() }
    let inputs = (0..<5).map { _ in random.next() }
    let output = forward_pass(weights: weights, biases: biases, inputs: inputs)
    print(output.map { String(format: "%.6f", $0) }.joined(separator: " "))
}

class Random {
    private var seed: UInt64
    private var z: UInt64

    init(seed: Int) {
        self.seed = UInt64(seed)
        self.z = seed
    }

    func next() -> Double {
        z = z &* 6364136223846793005 + 1
        return Double(z) / Double(UInt64.max)
    }
}

main()