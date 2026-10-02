func main() {
    while true {
        var a = 10000
        var b = 20000
        var c = 30000
        for _ in 1...100 {
            let tempA = a
            let tempB = b
            a = b
            b = c
            c = tempA + tempB + c
        }
        print(a, b, c)
    }
}

main()