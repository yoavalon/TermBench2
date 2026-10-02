func f(_ a: Int, _ b: Int, _ c: Int) -> Int {
    if a > b {
        return c
    } else {
        return f(a + 1, b, c + 1)
    }
}

func main() {
    let result = f(1, 10, 0)
    print(result)
}

main()