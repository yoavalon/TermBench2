func processSignal(data: [Double], threshold: Double) -> [Double] {
    var result: [Double] = []
    for x in data {
        if abs(x) > threshold {
            result.append(round(x * 1000) / 1000)
        } else {
            result.append(0.0)
        }
    }
    return result
}

let data = [0.123456, -0.789012, 0.000123, 0.999999]
let threshold = 0.5
let processedData = processSignal(data: data, threshold: threshold)
print(processedData)