import Foundation

class MatrixOp {
    var data: [[Double]]

    init(_ data: [[Double]]) {
        self.data = data
    }

    func multiply(_ other: MatrixOp) -> MatrixOp {
        let result = (0..<data.count).map { i in
            (0..<other.data[0].count).map { j in
                (0..<other.data.count).reduce(0) { $0 + data[i][$2] * other.data[$2][j] }
            }
        }
        return MatrixOp(result)
    }

    func add(_ other: MatrixOp) -> MatrixOp {
        let result = (0..<data.count).map { i in
            (0..<data[i].count).map { j in
                data[i][j] + other.data[i][j]
            }
        }
        return MatrixOp(result)
    }

    func sigmoid() -> MatrixOp {
        let result = data.map { row in
            row.map { 1 / (1 + exp(-$0)) }
        }
        return MatrixOp(result)
    }

    func relu() -> MatrixOp {
        let result = data.map { row in
            row.map { max(0, $0) }
        }
        return MatrixOp(result)
    }
}

class NeuralNetwork {
    var layers: [Layer]

    init(layers: [Layer]) {
        self.layers = layers
    }

    func forward_pass(input_data: MatrixOp) -> MatrixOp {
        var result = input_data
        for layer in layers {
            result = layer.forward(input_data: result)
        }
        return result
    }
}

class Layer {
    var weights: MatrixOp
    var activation: (MatrixOp) -> MatrixOp

    init(weights: [[Double]], activation: @escaping (MatrixOp) -> MatrixOp) {
        self.weights = MatrixOp(weights)
        self.activation = activation
    }

    func forward(input_data: MatrixOp) -> MatrixOp {
        let weighted_input = weights.multiply(input_data)
        let activated_output = activation(weighted_input)
        return activated_output
    }
}

func main() {
    let input_data = MatrixOp([
        [Double.random(in: 0..<1)],
        [Double.random(in: 0..<1)],
        [Double.random(in: 0..<1)]
    ])
    let weights1 = [
        [Double.random(in: 0..<1), Double.random(in: 0..<1), Double.random(in: 0..<1)],
        [Double.random(in: 0..<1), Double.random(in: 0..<1), Double.random(in: 0..<1)]
    ]
    let weights2 = [
        [Double.random(in: 0..<1), Double.random(in: 0..<1)]
    ]
    let layer1 = Layer(weights: weights1, activation: MatrixOp.sigmoid)
    let layer2 = Layer(weights: weights2, activation: MatrixOp.relu)
    let network = NeuralNetwork(layers: [layer1, layer2])
    let output = network.forward_pass(input_data: input_data)
    print(output.data)
}

main()