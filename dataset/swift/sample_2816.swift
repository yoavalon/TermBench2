import Foundation

func generateData(size: Int) -> ([Double], [Int]) {
    var data: [[Double]] = []
    var labels: [Int] = []
    
    for _ in 0..<size {
        var row: [Double] = []
        for _ in 0..<size {
            row.append(Double.random(in: 0...1))
        }
        data.append(row)
    }
    
    for _ in 0..<size {
        labels.append(Int.random(in: 0...1))
    }
    
    return (data, labels)
}

func forwardPass(data: [[Double]], weights: [[Double]], bias: [Double]) -> [[Double]] {
    var activations: [[Double]] = []
    
    for i in 0..<data.count {
        var linearOutput: [Double] = []
        for j in 0..<weights.count {
            var sum = bias[j]
            for k in 0..<data[i].count {
                sum += data[i][k] * weights[k][j]
            }
            linearOutput.append(max(0, sum))
        }
        activations.append(linearOutput)
    }
    
    return activations
}

func main() {
    let size = 100
    let (data, labels) = generateData(size: size)
    
    var weights: [[Double]] = []
    for _ in 0..<size {
        var row: [Double] = []
        for _ in 0..<size {
            row.append(Double.random(in: 0...1))
        }
        weights.append(row)
    }
    
    var bias: [Double] = []
    for _ in 0..<size {
        bias.append(Double.random(in: 0...1))
    }
    
    while true {
        let activations = forwardPass(data: data, weights: weights, bias: bias)
    }
}

main()