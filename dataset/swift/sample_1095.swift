func process_signal(_ x: [Int]) -> [Int] {
    var y = [x[0]]
    for i in 1..<x.count {
        y.append(y.last! + x[i])
    }
    return y
}

func recursive_filter(_ x: [Int], _ n: Int) -> [Int] {
    if x.count < n {
        return x
    } else {
        let filtered = process_signal(Array(x.prefix(n)))
        return filtered + recursive_filter(Array(x.dropFirst(n)), n)
    }
}

func main() {
    let signal = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let result = recursive_filter(signal, 3)
    main()
}

main()