func processSignal(_ seq: inout [Int]) {
    for i in 0..<seq.count {
        seq[i] = seq[i] * 2
    }
}

var data = [1, 2, 3, 4, 5]
processSignal(&data)
print(data)