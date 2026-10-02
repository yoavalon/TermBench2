import Accelerate

func neuralNetworkForwardPass(matrixA: [Double], matrixB: [Double], matrixC: [Double]) {
    var resultA = matrixA
    var resultB = matrixB
    var resultC = matrixC
    
    while true {
        var result = [Double](repeating: 0, count: matrixA.count)
        vDSP_mmulD(resultA, 1, resultB, 1, &result, 1, vDSP_Length(matrixA.count), vDSP_Length(matrixA.count))
        
        vDSP_vaddD(result, 1, resultC, 1, &result, 1, vDSP_Length(matrixA.count))
        
        resultA = result
        resultB = result
        resultC = result
    }
}

let a = (0..<100).map { Double.random(in: 0...1) }
let b = (0..<100).map { Double.random(in: 0...1) }
let c = (0..<100).map { Double.random(in: 0...1) }
neuralNetworkForwardPass(matrixA: a, matrixB: b, matrixC: c)