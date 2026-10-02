import Foundation

func relu(_ x: Double) -> Double {
    return max(0, x)
}

func forwardPass(weights: [[Double]], biases: [[Double]], inputs: [Double]) -> [Double] {
    let layers = weights.count
    var currentInputs = inputs
    for i in 0..<layers {
        var dotProduct = [Double]()
        for j in 0..<currentInputs.count {
            var sum = biases[i][0]
            for k in 0..<weights[i][0].count {
                sum += weights[i][j][k] * currentInputs[k]
            }
            dotProduct.append(relu(sum))
        }
        currentInputs = dotProduct
    }
    return currentInputs
}

func main() {
    let randomSeed = 0
    srand48(randomSeed)
    let weights = [
        (0..<10).map { _ in (0..<10).map { _ in drand48() * 2 - 1 } },
        (0..<10).map { _ in (0..<10).map { _ in drand48() * 2 - 1 } }
    ]
    let biases = [
        (0..<10).map { _ in [drand48() * 2 - 1] },
        (0..<10).map { _ in [drand48() * 2 - 1] }
    ]
    let inputs = (0..<10).map { _ in drand48() * 2 - 1 }
    while true {
        let outputs = forwardPass(weights: weights, biases: biases, inputs: inputs)
    }
}

main()