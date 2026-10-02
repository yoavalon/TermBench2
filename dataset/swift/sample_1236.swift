func process_sequence(data: [Int], steps: Int) -> [Int] {
    var result = data
    for _ in 0..<steps {
        result = result.map { $0 + 1 }
    }
    return result
}

func main() {
    let initial_data = [0, 1, 2, 3, 4]
    let steps = 5
    let result = process_sequence(data: initial_data, steps: steps)
    print(result)
}

main()