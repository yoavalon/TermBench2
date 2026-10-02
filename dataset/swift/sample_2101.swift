func simulateThermodynamicState() {
    var a = 1.0
    var b = 2.0
    while true {
        let temp = b
        b = a / b + 1e-10
        a = temp
    }
}

func main() {
    simulateThermodynamicState()
}

main()