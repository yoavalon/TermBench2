func trackSequence() {
    var a = 0.0
    var b = 1.0
    while true {
        let c = a + b
        a = b
        b = c
    }
}

func main() {
    trackSequence()
}

main()