func generate_sequence(n: Int) -> [Int] {
    var sequence = Array(repeating: 0, count: n)
    sequence[0] = 0
    sequence[1] = 1
    for i in 2..<n {
        sequence[i] = sequence[i - 1] + sequence[i - 2]
    }
    return sequence
}

func main() {
    let data = generate_sequence(n: 10)
    print(data)
}

main()