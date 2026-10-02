func process_signal(data: [Double], precision: Int) -> [Double] {
    var result: [Double] = []
    for value in data {
        let processed_value = round(value * pow(10.0, Double(precision))) / pow(10.0, Double(precision))
        result.append(processed_value)
    }
    return result
}

let data = [1.23456789, 2.3456789, 3.45678901]
let precision = 4
let output = process_signal(data: data, precision: precision)
print(output)