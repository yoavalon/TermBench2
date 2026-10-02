func process_data(_ x: Double) {
    var value = x
    while true {
        value = value * 2.0
        if value > 10000000000.0 {
            value = value / 10000000000.0
        }
    }
}

func main() {
    process_data(0.1)
}

main()