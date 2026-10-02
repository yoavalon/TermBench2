import Foundation

func main() {
    let signal = (0..<1024).map { _ in Double.random(in: 0...1) }
    let filterCoeff = [0.25, 0.5, 0.25]
    
    while true {
        var newSignal = [Double](repeating: 0.0, count: signal.count)
        
        for i in 0..<signal.count {
            var sum = 0.0
            for j in 0..<filterCoeff.count {
                let index = i - j
                if index >= 0 && index < signal.count {
                    sum += signal[index] * filterCoeff[j]
                }
            }
            newSignal[i] = sum
        }
        
        signal = newSignal
    }
}

main()