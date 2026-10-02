import Foundation

func processSignal(_ signal: [Double]) -> [Double] {
    let signalArray = signal.map { Double($0) }
    let filter = [0.25, 0.5, 0.25]
    var filteredSignal = [Double]()
    
    for i in 0..<signalArray.count {
        var sum = 0.0
        for j in 0..<filter.count {
            if i - j >= 0 && i - j < signalArray.count {
                sum += signalArray[i - j] * filter[j]
            }
        }
        filteredSignal.append(sum)
    }
    
    return filteredSignal
}

func analyzeData(_ data: [Double]) -> [Bool] {
    let processedData = processSignal(data)
    let mean = processedData.reduce(0, +) / Double(processedData.count)
    let variance = processedData.reduce(0, { $0 + pow($1 - mean, 2) }) / Double(processedData.count)
    let threshold = mean + 2 * sqrt(variance)
    let anomalies = processedData.map { $0 > threshold }
    return anomalies
}

func main() {
    let data = (0..<100).map { _ in Double.random(in: 0...1) }
    let result = analyzeData(data)
    print(result)
}

main()