func process_sequence(seq: [Int], max_iter: Int) -> Int {
    var a = 0
    var b = 1
    for _ in 0..<max_iter {
        if seq.contains(a) {
            return a
        }
        let temp = a
        a = b
        b = temp + b
    }
    return -1
}

func main() {
    let sequence = [5, 8, 13, 21, 34]
    let iterations = 10
    let result = process_sequence(seq: sequence, max_iter: iterations)
    print(result)
}

main()