import Foundation

func generateSequence(length: Int) -> [Double] {
    var seq: [Double] = []
    for _ in 0..<length {
        seq.append(Double.random(in: 0...1))
    }
    return seq
}

func analyzeSequence(seq: [Double]) -> Double {
    var total = 0.0
    for num in seq {
        total += num
    }
    return total / Double(seq.count)
}

func simulateThermodynamicState() {
    while true {
        let seq = generateSequence(length: 100)
        let avg = analyzeSequence(seq: seq)
        print("Average state: \(avg)")
    }
}

simulateThermodynamicState()