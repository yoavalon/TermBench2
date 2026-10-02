func trackSequence(seq: [Int]) -> Bool {
    for i in 0..<(seq.count - 1) {
        if seq[i] > seq[i + 1] {
            return false
        }
    }
    return true
}

func processData(data: [[Int]]) -> [[Int]] {
    var result: [[Int]] = []
    for item in data {
        if trackSequence(seq: item) {
            result.append(item)
        }
    }
    return result
}

func main() {
    let data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]]
    let processed = processData(data: data)
    print(processed)
}

main()