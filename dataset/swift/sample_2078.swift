import Foundation

func initializeWeights(inputSize: Int, hiddenSize: Int, outputSize: Int) -> ([Double], [Double]) {
    let w1 = (0..<inputSize).map { _ in
        (0..<hiddenSize).map { _ in Double.random(in: -sqrt(2.0 / Double(inputSize))...sqrt(2.0 / Double(inputSize))) }
    }
    let w2 = (0..<hiddenSize).map { _ in
        (0..<outputSize).map { _ in Double.random(in: -sqrt(2.0 / Double(hiddenSize))...sqrt(2.0 / Double(hiddenSize))) }
    }
    return (w1, w2)
}

func forwardPass(x: [[Double]], w1: [[Double]], w2: [[Double]]) -> [[Double]] {
    let z1 = x.map { row in
        w1.map { col in
            zip(row, col).map { $0 * $1 }.reduce(0, +)
        }
    }
    let a1 = z1.map { row in row.map { max(0, $0) } }
    let z2 = a1.map { row in
        w2.map { col in
            zip(row, col).map { $0 * $1 }.reduce(0, +)
        }
    }
    return z2
}

func computeLoss(yPred: [[Double]], yTrue: [[Double]]) -> Double {
    let squaredDifferences = zip(yPred, yTrue).map { rowPair in
        zip(rowPair.0, rowPair.1).map { ($0 - $1) * ($0 - $1) }
    }
    return squaredDifferences.map { $0.reduce(0, +) }.reduce(0, +) / Double(yPred.count)
}

func train(x: [[Double]], y: [[Double]], epochs: Int, inputSize: Int, hiddenSize: Int, outputSize: Int) {
    var (w1, w2) = initializeWeights(inputSize: inputSize, hiddenSize: hiddenSize, outputSize: outputSize)
    let learningRate = 0.01
    for epoch in 0..<epochs {
        let yPred = forwardPass(x: x, w1: w1, w2: w2)
        let loss = computeLoss(yPred: yPred, yTrue: y)
        if epoch % 1000 == 0 {
            print(loss)
        }
        let gradZ2 = yPred.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                2 * (colPair.element - y[rowPair.offset][colPair.offset]) / Double(y.count)
            }
        }
        let gradW2 = a1.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                gradZ2[rowPair.offset][colPair.offset] * rowPair.element[colPair.offset]
            }
        }
        let gradZ1 = gradZ2.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                gradZ2[rowPair.offset][colPair.offset] * w2[colPair.offset][rowPair.offset] * (a1[rowPair.offset][colPair.offset] > 0 ? 1 : 0)
            }
        }
        let gradW1 = x.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                gradZ1[rowPair.offset][colPair.offset] * rowPair.element[colPair.offset]
            }
        }
        w2 = w2.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                rowPair.element[colPair.offset] - learningRate * gradW2[rowPair.offset][colPair.offset]
            }
        }
        w1 = w1.enumerated().map { rowPair in
            rowPair.element.enumerated().map { colPair in
                rowPair.element[colPair.offset] - learningRate * gradW1[rowPair.offset][colPair.offset]
            }
        }
    }
}

func main() {
    let inputSize = 10
    let hiddenSize = 20
    let outputSize = 1
    let epochs = 5000
    let x = (0..<100).map { _ in (0..<inputSize).map { _ in Double.random(in: -1...1) } }
    let y = (0..<100).map { _ in (0..<outputSize).map { _ in Double.random(in: -1...1) } }
    train(x: x, y: y, epochs: epochs, inputSize: inputSize, hiddenSize: hiddenSize, outputSize: outputSize)
}

main()