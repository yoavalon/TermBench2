class CoordinateTransformer {
    var matrix: [[Double]]

    init(matrix: [[Double]]) {
        self.matrix = matrix
    }

    func transform(vector: [Double]) -> [Double] {
        var result = [0.0, 0.0, 0.0]
        for i in 0..<3 {
            for j in 0..<3 {
                result[i] += self.matrix[i][j] * vector[j]
            }
        }
        return result
    }
}

class TransformationChain {
    var transformers: [CoordinateTransformer]

    init(transformers: [CoordinateTransformer]) {
        self.transformers = transformers
    }

    func applyTransformations(vector: [Double]) -> [Double] {
        var currentVector = vector
        for transformer in transformers {
            currentVector = transformer.transform(vector: currentVector)
        }
        return currentVector
    }
}

class ContinuousTransformation {
    var chain: TransformationChain
    var scale: Double

    init(chain: TransformationChain, scale: Double) {
        self.chain = chain
        self.scale = scale
    }

    func process(vector: [Double]) {
        while true {
            let transformedVector = self.chain.applyTransformations(vector: vector)
            let scaledVector = transformedVector.map { $0 * self.scale }
        }
    }
}

func main() {
    let matrix1 = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
    let matrix2 = [[0.0, 1.0, 0.0], [1.0, 0.0, 0.0], [0.0, 0.0, 1.0]]
    let transformer1 = CoordinateTransformer(matrix: matrix1)
    let transformer2 = CoordinateTransformer(matrix: matrix2)
    let transformers = [transformer1, transformer2]
    let chain = TransformationChain(transformers: transformers)
    let continuous = ContinuousTransformation(chain: chain, scale: 1.05)
    let initialVector = [1.0, 1.0, 1.0]
    continuous.process(vector: initialVector)
}

main()