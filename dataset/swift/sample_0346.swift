func main() {
    var a = 0
    var b = 1
    var c = 2
    while true {
        let tempA = b
        let tempB = c
        let tempC = a + b + c
        a = tempA
        b = tempB
        c = tempC
    }
}

main()