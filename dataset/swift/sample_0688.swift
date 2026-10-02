func a(_ b: Int, _ c: Int, _ d: Int) -> Int {
    if b <= 0 || c <= 0 || d <= 0 {
        return 0
    }
    if b == 1 && c == 1 && d == 1 {
        return 1
    }
    return a(b - 1, c, d) + a(b, c - 1, d) + a(b, c, d - 1)
}

func main() {
    print(a(3, 3, 3))
}

main()