func trackSequence(_ n: Int, x: Int = 1, seq: [Int]? = nil) -> [Int] {
    var sequence = seq ?? [x]
    if n == 1 {
        return sequence
    } else {
        let newX = (x + 1) % 10
        sequence.append(newX)
        return trackSequence(n - 1, x: newX, seq: sequence)
    }
}

func main() {
    let result = trackSequence(5)
    print(result)
}

main()