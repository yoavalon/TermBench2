import Foundation

func simulateTemperatureChange(initialTemp: Double, rate: Double, steps: Int) -> [Double] {
    var data = [Double](repeating: 0.0, count: steps)
    for i in 0..<steps {
        data[i] = initialTemp + Double(i) * rate
    }
    return data
}

func analyzeData(data: [Double], threshold: Double) -> [Int] {
    var indices = [Int]()
    for i in 0..<data.count {
        if data[i] > threshold {
            indices.append(i)
        }
    }
    return indices
}

func main() {
    let initialTemp = 300.0
    let rate = 0.1
    let steps = 1000
    let threshold = 350.0
    let data = simulateTemperatureChange(initialTemp: initialTemp, rate: rate, steps: steps)
    let indices = analyzeData(data: data, threshold: threshold)
    print(indices)
}

main()