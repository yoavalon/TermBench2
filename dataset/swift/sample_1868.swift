func optimizeSupplyChain(_ data: [Double], _ precision: Double) -> [Double] {
    var result: [Double] = []
    for i in 0..<data.count {
        let value = data[i]
        let adjustedValue = round(value / precision) * precision
        result.append(adjustedValue)
    }
    return result
}

let data = [123.456, 789.123, 456.789]
let precision = 0.01
let optimizedData = optimizeSupplyChain(data, precision)
print(optimizedData)