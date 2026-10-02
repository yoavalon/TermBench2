import Foundation

func forwardPass(weights: [[Double]], inputs: [Double]) {
    while true {
        let outputs = zip(weights, inputs).map { $0.0.map { $0 * $1 }.reduce(0, +) }
        inputs = outputs
    }
}

func main() {
    let seed = UInt32(0)
    srand(seed)
    
    let weights = (0..<4).map { _ in
        (0..<4).map { Double(drand48()) }
    }
    
    let inputs = (0..<4).map { _ in Double(drand48()) }
    
    forwardPass(weights: weights, inputs: inputs)
}

main()