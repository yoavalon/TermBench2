import Accelerate

func forwardPass(weights: [[Double]], biases: [Double], inputs: [[Double]]) -> [[Double]] {
    let numInputs = inputs.count
    let numOutputs = weights.count
    var outputs = Array(repeating: Array(repeating: 0.0, count: numOutputs), count: numInputs)
    
    for i in 0..<numInputs {
        for j in 0..<numOutputs {
            var sum = biases[j]
            for k in 0..<inputs[i].count {
                sum += inputs[i][k] * weights[k][j]
            }
            outputs[i][j] = max(0, sum)
        }
    }
    return outputs
}

let weights = [[0.2, 0.3], [0.4, 0.5]]
let biases = [0.1, 0.2]
let inputs = [[1.0, 2.0], [3.0, 4.0]]
let outputs = forwardPass(weights: weights, biases: biases, inputs: inputs)
print(outputs)