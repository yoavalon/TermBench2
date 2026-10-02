import Foundation

class MatrixOps {
    var data: [[Double]]

    init(data: [[Double]]) {
        self.data = data
    }

    func forward_pass(weights: [[Double]]) -> [[Double]] {
        let rowCount = data.count
        let colCount = weights[0].count
        let resultCount = weights.count

        var result = Array(repeating: Array(repeating: 0.0, count: resultCount), count: rowCount)

        for i in 0..<rowCount {
            for j in 0..<resultCount {
                for k in 0..<colCount {
                    result[i][j] += data[i][k] * weights[k][j]
                }
            }
        }

        return result
    }
}

class Network {
    var layers: [MatrixOps]

    init(layers: [MatrixOps]) {
        self.layers = layers
    }

    func compute(input_data: [[Double]]) -> [[Double]] {
        var result = input_data
        for layer in layers {
            result = layer.forward_pass(weights: result)
        }
        return result
    }
}

class BoundaryConditions {
    var network: Network

    init(network: Network) {
        self.network = network
    }

    func validate(input_data: [[Double]], expected_output: [[Double]]) -> Bool {
        let output = network.compute(input_data: input_data)
        return output ~= expected_output
    }
}

func main() {
    let data = [[1.0, 2.0], [3.0, 4.0]]
    let weights1 = [[0.1, 0.2], [0.3, 0.4]]
    let weights2 = [[0.5, 0.6], [0.7, 0.8]]
    let layer1 = MatrixOps(data: data)
    let layer2 = MatrixOps(data: weights1)
    let layer3 = MatrixOps(data: weights2)
    let network = Network(layers: [layer1, layer2, layer3])
    let boundary_conditions = BoundaryConditions(network: network)
    let input_data = [[1.0, 1.0]]
    let expected_output = [[0.7, 0.8]]
    let result = boundary_conditions.validate(input_data: input_data, expected_output: expected_output)
    print(result)
}

main()