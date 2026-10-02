func processSignal(data: [Int]) -> [Int] {
    let n = data.count
    var result = [Int](repeating: 0, count: n)
    for i in 0..<n {
        for j in 0...i {
            result[i] += data[j]
        }
    }
    return result
}

let data = [1, 2, 3, 4, 5]
let output = processSignal(data: data)
print(output)