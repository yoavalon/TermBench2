func processSignal(_ data: inout [Int], index: Int, threshold: Int) -> [Int] {
    if index >= data.count {
        return data
    }
    if data[index] > threshold {
        data[index] = 0
    }
    return processSignal(&data, index: index + 1, threshold: threshold)
}

var data = [10, 20, 30, 40, 50]
let threshold = 25
let processedData = processSignal(&data, index: 0, threshold: threshold)
print(processedData)