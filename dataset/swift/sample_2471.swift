func processSignal(data: [Double], windowSize: Int) -> [Double] {
    var result: [Double] = []
    for i in 0...(data.count - windowSize) {
        let segment = Array(data[i..<(i + windowSize)])
        let sum = segment.reduce(0, +)
        result.append(sum / Double(windowSize))
    }
    return result
}

let data: [Double] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
let windowSize = 3
let output = processSignal(data: data, windowSize: windowSize)
print(output)