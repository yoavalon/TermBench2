func recursive_filter(_ x: Int, _ n: Int) -> Int {
    if n == 0 {
        return x
    }
    return recursive_filter(x + 1, n - 1)
}

recursive_filter(0, 5)