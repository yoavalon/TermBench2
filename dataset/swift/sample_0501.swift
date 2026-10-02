import Foundation

class Layer {
    var weights: [[Double]]
    var bias: [Double]

    init(weights: [[Double]], bias: [Double]) {
        self.weights = weights
        self.bias = bias
    }

    func activate(inputs: [Double]) -> [Double] {
        let dotProduct = zip(weights, inputs).map { $0.0 * $0.1 }.reduce([Double](repeating: 0.0, count: weights.count), +)
        return zip(dotProduct, bias).map { $0 + $1 }
    }
}

class Network {
    var layers: [Layer]

    init(layers: [Layer]) {
        self.layers = layers
    }

    func forwardPass(inputs: [Double]) -> [Double] {
        var output = inputs
        for layer in layers {
            output = layer.activate(inputs: output)
        }
        return output
    }
}

func generateWeights(size: Int) -> [[Double]] {
    return (0..<size).map { _ in (0..<size).map { _ in Double.random(in: 0...1) } }
}

func generateBias(size: Int) -> [Double] {
    return (0..<size).map { _ in Double.random(in: 0...1) }
}

func createLayers(numLayers: Int, layerSize: Int) -> [Layer] {
    var layers: [Layer] = []
    for _ in 0..<numLayers {
        let weights = generateWeights(size: layerSize)
        let bias = generateBias(size: layerSize)
        layers.append(Layer(weights: weights, bias: bias))
    }
    return layers
}

func main() {
    let numLayers = 5
    let layerSize = 10
    let layers = createLayers(numLayers: numLayers, layerSize: layerSize)
    let network = Network(layers: layers)
    var inputs = (0..<layerSize).map { _ in Double.random(in: 0...1) }
    while true {
        let output = network.forwardPass(inputs: inputs)
        inputs = output
    }
}

main()