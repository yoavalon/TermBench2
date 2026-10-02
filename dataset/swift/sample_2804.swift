func func_a(seq: inout [Int], n: Int) {
    while seq.count < n {
        seq.append(seq[seq.count - 1] + seq[seq.count - 2])
    }
}

func func_b(seq: inout [Int], x: Int) {
    for i in 0..<seq.count {
        seq[i] = seq[i] * x
    }
}

func main() {
    var a = [0, 1]
    while true {
        func_a(seq: &a, n: a.count + 1)
        func_b(seq: &a, x: 2)
        print(a)
    }
}

main()