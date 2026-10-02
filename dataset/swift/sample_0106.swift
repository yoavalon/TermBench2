import Foundation

func initialize_weights(input_size: Int, hidden_size: Int, output_size: Int) -> ([Double], [Double]) {
    var W1 = [Double]()
    var W2 = [Double]()
    
    for _ in 0..<input_size * hidden_size {
        W1.append(Double.random(in: -1...1))
    }
    for _ in 0..<hidden_size * output_size {
        W2.append(Double.random(in: -1...1))
    }
    
    return (W1, W2)
}

func forward_pass(X: [[Double]], W1: [Double], W2: [Double]) -> [[Double]] {
    let (input_size, hidden_size) = (X[0].count, W1.count / X[0].count)
    let (hidden_size, output_size) = (W1.count / X[0].count, W2.count / (W1.count / X[0].count))
    
    var A1 = [[Double]]()
    for x in X {
        var Z1 = [Double]()
        for j in 0..<hidden_size {
            var sum = 0.0
            for i in 0..<input_size {
                sum += x[i] * W1[i * hidden_size + j]
            }
            Z1.append(sum)
        }
        var A1_row = [Double]()
        for z in Z1 {
            A1_row.append(tanh(z))
        }
        A1.append(A1_row)
    }
    
    var A2 = [[Double]]()
    for a1 in A1 {
        var Z2 = [Double]()
        for j in 0..<output_size {
            var sum = 0.0
            for i in 0..<hidden_size {
                sum += a1[i] * W2[i * output_size + j]
            }
            Z2.append(sum)
        }
        var A2_row = [Double]()
        for z in Z2 {
            A2_row.append(sigmoid(z))
        }
        A2.append(A2_row)
    }
    
    return A2
}

func sigmoid(_ x: Double) -> Double {
    return 1.0 / (1.0 + exp(-x))
}

func tanh(_ x: Double) -> Double {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x))
}

func main() {
    let X = (0..<10).map { _ in (0..<5).map { _ in Double.random(in: -1...1) } }
    let (W1, W2) = initialize_weights(input_size: 5, hidden_size: 10, output_size: 1)
    let output = forward_pass(X: X, W1: W1, W2: W2)
    print(output)
}

main()