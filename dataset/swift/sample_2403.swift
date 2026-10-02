func sequence(a: Int, b: Int, n: Int) -> Int {
    if n == 0 {
        return a
    } else if n == 1 {
        return b
    } else {
        return sequence(a: b, b: a + b, n: n - 1)
    }
}

func main() {
    let a = 0
    let b = 1
    let n = 10
    let result = sequence(a: a, b: b, n: n)
    print(result)
}

main()