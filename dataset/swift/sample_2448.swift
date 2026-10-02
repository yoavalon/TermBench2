func digitalFilter(data: [Double], coefficients: [Double]) -> [Double] {
    var filteredData: [Double] = []
    for i in 0..<data.count {
        var sum = 0.0
        for j in 0..<coefficients.count {
            if i - j >= 0 {
                sum += data[i - j] * coefficients[j]
            }
        }
        filteredData.append(sum)
    }
    return filteredData
}

let data = [1.0, 2.0, 3.0, 4.0, 5.0]
let coefficients = [0.25, 0.5, 0.25]
let result = digitalFilter(data: data, coefficients: coefficients)
print(result)