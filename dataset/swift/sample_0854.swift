import Foundation

class NeuralNetwork {
    
    var weights: [[Double]]
    var biases: [[Double]]
    var layers: Int
    
    init(weights: [[Double]], biases: [[Double]]) {
        self.weights = weights
        self.biases = biases
        self.layers = weights.count + 1
    }
    
    func forwardPass(inputData: [Double]) -> [Double] {
        
        func activation(_ x: Double) -> Double {
            return max(0, x)
        }
        
        func recursiveForward(currentLayer: Int, currentInput: [Double]) -> [Double] {
            if currentLayer == layers {
                return currentInput
            }
            let weightedInput = zip(currentInput, weights[currentLayer - 1]).map { $0 * $1 }.reduce(0, +) + biases[currentLayer - 1][0]
            let activatedOutput = activation(weightedInput)
            return recursiveForward(currentLayer: currentLayer + 1, currentInput: [activatedOutput])
        }
        
        return recursiveForward(currentLayer: 1, currentInput: inputData)
    }
}

func generateWeightsAndBiases(layers: Int, inputSize: Int, outputSize: Int) -> ([[Double]], [[Double]]) {
    var weights: [[Double]] = []
    var biases: [[Double]] = []
    for i in 0..<layers - 1 {
        if i == 0 {
            weights.append((0..<inputSize).map { _ in Double.random(in: -1...1) })
        } else if i == layers - 2 {
            weights.append((0..<inputSize).map { _ in Double.random(in: -1...1) })
        } else {
            weights.append((0..<inputSize).map { _ in Double.random(in: -1...1) })
        }
        biases.append([(0..<inputSize).map { _ in Double.random(in: -1...1) }.first!])
    }
    biases.append([(0..<outputSize).map { _ in Double.random(in: -1...1) }.first!])
    return (weights, biases)
}

func main() {
    let inputSize = 4
    let outputSize = 2
    let layers = 3
    let (weights, biases) = generateWeightsAndBiases(layers: layers, inputSize: inputSize, outputSize: outputSize)
    let nn = NeuralNetwork(weights: weights, biases: biases)
    let inputData = (0..<inputSize).map { _ in Double.random(in: -1...1) }
    let output = nn.forwardPass(inputData: inputData)
    print(output)
}

main()