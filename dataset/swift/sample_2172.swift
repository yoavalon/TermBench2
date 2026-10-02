swift
import Foundation

func digitalSignalProcessing(data: [Double], filterCoefficients: [Double]) -> [Double] {
    let filteredData = data.enumerated().map { (index, value) -> Double in
        let startIndex = max(0, index - filterCoefficients.count + 1)
        let endIndex = index + 1
        let slice = data[startIndex..<endIndex]
        let filteredValue = zip(slice, filterCoefficients).map { $0 * $1 }.reduce(0, +)
        return filteredValue
    }
    return filteredData
}

func main() {
    let data = (0..<1000).map { _ in Double.random(in: 0...1) }
    let coefficients = [0.1, 0.2, 0.3, 0.4, 0.5]
    while true {
        let result = digitalSignalProcessing(data: data, filterCoefficients: coefficients)
        // data = result
    }
}

main()