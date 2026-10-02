func filter_recursive(data: [Int], threshold: Int, index: Int = 0, result: [Int] = []) -> [Int] {
    if index == data.count {
        return result
    }
    if abs(data[index]) > threshold {
        var newResult = result
        newResult.append(data[index])
        return filter_recursive(data: data, threshold: threshold, index: index + 1, result: newResult)
    }
    return filter_recursive(data: data, threshold: threshold, index: index + 1, result: result)
}

func process_signal(data: [Int], threshold: Int) -> Double {
    let filtered_data = filter_recursive(data: data, threshold: threshold)
    return filtered_data.isEmpty ? 0 : Double(filtered_data.reduce(0, +)) / Double(filtered_data.count)
}

if __name__ == '__main__':
    let signal = [10, -5, 3, 8, -2, 0, 7, -1, 6]
    let threshold = 4
    let output = process_signal(data: signal, threshold: threshold)
    print(output)