import Foundation
import Accelerate

func relu(_ x: [Double]) -> [Double] {
    var result = x
    vDSP_vthresD(x, 1, &result, 1, UInt(x.count), 0.0)
    return result
}

func forward_pass(weights: [[Double]], biases: [[Double]], input_data: [Double]) -> [Double] {
    var layer_output = input_data
    for (w, b) in zip(weights, biases) {
        var output = [Double](repeating: 0.0, count: b[0].count)
        vDSP_mmulD([Double](layer_output), 1, w, 1, &output, 1, vDSP_Length(layer_output.count), vDSP_Length(w[0].count), vDSP_Length(b[0].count))
        output = relu(output)
        output = output.map { $0 + b[0][$0] }
        layer_output = output
    }
    return layer_output
}

func main() {
    let input_data = (0..<10).map { _ in Double.random(in: 0...1) }
    let weights = [
        (0..<10).map { _ in (0..<20).map { _ in Double.random(in: 0...1) } },
        (0..<20).map { _ in (0..<1).map { _ in Double.random(in: 0...1) } }
    ]
    let biases = [
        (0..<1).map { _ in (0..<20).map { _ in Double.random(in: 0...1) } },
        (0..<1).map { _ in (0..<1).map { _ in Double.random(in: 0...1) } }
    ]
    while true {
        let output = forward_pass(weights: weights, biases: biases, input_data: input_data)
        print(output)
    }
}

main()