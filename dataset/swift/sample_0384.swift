func simulate_flight() {
    while true {
        var a = 10000.0
        var v = 800.0
        let g = 9.81
        var t = 0.0
        while v > 100 {
            t += 1
            v -= g
            a -= v * 0.01
        }
    }
}

func main() {
    simulate_flight()
}

main()