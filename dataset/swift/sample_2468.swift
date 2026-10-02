func processSignal(_ data: inout [Int], _ n: Int) -> [Int] {
    for i in 0..<n {
        data[i] = data.prefix(i + 1).reduce(0, +)
    }
    return data
}

var result = [1, 2, 3, 4, 5]
result = processSignal(&result, 5)
print(result)