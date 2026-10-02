class SignalProcessor {
    var data: [Int]
    var threshold: Int

    init(data: [Int], threshold: Int) {
        self.data = data
        self.threshold = threshold
    }

    func filterData(index: Int = 0) -> [Int] {
        if index >= data.count {
            return []
        }
        if abs(data[index]) > threshold {
            return [data[index]] + filterData(index: index + 1)
        }
        return filterData(index: index + 1)
    }
}

class DataAnalyzer {
    var processedData: [Int]

    init(processedData: [Int]) {
        self.processedData = processedData
    }

    func computeAverage(index: Int = 0, total: Int = 0) -> Double {
        if index >= processedData.count {
            return Double(total) / Double(processedData.count)
        }
        return computeAverage(index: index + 1, total: total + processedData[index])
    }

    func findMax(index: Int = 0, currentMax: Int? = nil) -> Int {
        let currentMax = currentMax ?? processedData[index]
        if index >= processedData.count {
            return currentMax
        }
        if processedData[index] > currentMax {
            return findMax(index: index + 1, currentMax: processedData[index])
        }
        return findMax(index: index + 1, currentMax: currentMax)
    }
}

func main() {
    let data = [1, 3, -5, 7, -9, 11, -13, 15, -17, 19]
    let threshold = 10
    let processor = SignalProcessor(data: data, threshold: threshold)
    let filteredData = processor.filterData()
    let analyzer = DataAnalyzer(processedData: filteredData)
    let average = analyzer.computeAverage()
    let maxValue = analyzer.findMax()
    print("Average:", average)
    print("Max Value:", maxValue)
}

main()