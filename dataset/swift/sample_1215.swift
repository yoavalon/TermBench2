func func(a: Int) -> Int {
    if a == 0 {
        return 1
    }
    return func(a: a - 1)
}
func(5)