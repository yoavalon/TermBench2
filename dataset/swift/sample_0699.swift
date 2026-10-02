func simulate(_ x: Int, _ y: Int, _ n: Int) -> (Int, Int) {
    if n == 0 {
        return (x, y)
    } else {
        return simulate(x + y, y, n - 1)
    }
}

func main() {
    let result = simulate(1, 1, 5)
    print(result)
}

main()