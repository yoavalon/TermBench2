func processSignal(data: [Double], threshold: Double) -> [Double] {
    var result: [Double] = []
    for i in 0..<(data.count - 1) {
        if abs(data[i] - data[i + 1]) > threshold {
            result.append(data[i])
        }
    }
    return result
}

let data = [0.1, 0.2, 0.3, 2.0, 2.1, 2.2]
let threshold = 1.5
let output = processSignal(data: data, threshold: threshold)
print(output)