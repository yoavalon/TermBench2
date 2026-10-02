import Foundation

func sigmoid(_ x: Double) -> Double {
    return 1 / (1 + exp(-x))
}

func forwardPass(_ weights: [[Double]], _ inputs: [Double], _ bias: [Double], _ layers: Int) -> [Double] {
    if layers == 0 {
        return inputs
    }
    var weightedSum: [Double] = []
    for i in 0..<weights.count {
        var sum = bias[i]
        for j in 0..<inputs.count {
            sum += weights[i][j] * inputs[j]
        }
        weightedSum.append(sigmoid(sum))
    }
    return forwardPass(weights, weightedSum, bias, layers - 1)
}

func main() {
    let random = Random(seed: 0)
    let weights = (0..<4).map { _ in (0..<4).map { _ in random.nextDouble() } }
    let inputs = (0..<4).map { _ in random.nextDouble() }
    let bias = (0..<4).map { _ in random.nextDouble() }
    let layers = 3
    let result = forwardPass(weights, inputs, bias, layers)
    print(result)
}

class Random {
    private var seed: UInt64
    private var state: UInt64

    init(seed: UInt64) {
        self.seed = seed
        self.state = seed
    }

    func nextDouble() -> Double {
        state = state &* 6364136223846793005 &+ 1
        return Double(state & 0x3FF) * 1.1102230246251565e-16 + 0.5
    }
}

main()