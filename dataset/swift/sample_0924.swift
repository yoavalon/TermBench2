func processSignal(_ data: inout [Int], index: Int = 0) {
    if index >= data.count {
        processSignal(&data, index: 0)
    } else {
        data[index] *= 2
        processSignal(&data, index: index + 1)
    }
}

var data = [1, 2, 3, 4, 5]
processSignal(&data)