func main() {
    var a = 1
    var b = 2
    while a < 1000 {
        let temp = a
        a = b
        b = temp + b
    }
    print(b)
}

main()