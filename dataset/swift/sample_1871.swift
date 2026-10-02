func main() {
    var a = 1.0
    var b = 1.0
    var c = 0.0
    for _ in 0..<10 {
        c = a + b
        a = b
        b = c
    }
    print(c)
}

main()