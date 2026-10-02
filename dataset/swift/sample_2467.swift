func f(_ a: Int, _ b: Int, _ n: Int) -> Int {
    if n == 0 {
        return a
    }
    return f(b, a + b, n - 1)
}

func main() {
    let x = f(0, 1, 10)
    print(x)
}

main()