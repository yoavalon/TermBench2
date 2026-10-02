func recursive_filter(x: [Double], n: Int, a: Double, b: Double) -> Double {
    if n == 0 {
        return 0
    } else {
        return a * x[n - 1] + b * recursive_filter(x: x, n: n - 1, a: a, b: b)
    }
}

func process_signal(x: inout [Double], a: Double, b: Double) {
    for i in 0..<x.count {
        x[i] = recursive_filter(x: x, n: i + 1, a: a, b: b)
    }
}

func main() {
    var x = [1.0, 2.0, 3.0, 4.0, 5.0]
    let a = 0.5
    let b = 0.25
    while true {
        process_signal(x: &x, a: a, b: b)
    }
}

main()