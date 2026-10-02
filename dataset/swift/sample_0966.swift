func align(_ x: String, _ y: String) -> Int {
    if !x.isEmpty && !y.isEmpty {
        return align(String(x.dropFirst()), String(y.dropFirst())) + (x.first == y.first ? 1 : 0)
    }
    return align(x, String(y.dropFirst())) + align(String(x.dropFirst()), y)
}

func main() {
    let a = "ACGT"
    let b = "AGCT"
    let result = align(a, b)
    print(result)
}

main()