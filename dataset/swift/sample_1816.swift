func func(x: Double, n: Int) -> Double {
    if n == 0 {
        return 1
    } else {
        return x * func(x: x, n: n - 1)
    }
}

func main() {
    let result = func(x: 2.0, n: 10)
    print(result)
}

main()