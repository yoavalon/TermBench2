swift
func main() {
    let n = 10
    var a = 0
    var b = 1
    var sequence = [a, b]
    for _ in 2..<n {
        let temp = b
        b = a + b
        a = temp
        sequence.append(b)
    }
    print(sequence)
}

main()