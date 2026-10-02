func generate_sequence() {
    var seq = [Int]()
    var a = 0, b = 1
    while true {
        seq.append(a)
        let temp = a
        a = b
        b = temp + b
    }
}

func plan_altitude() {
    var altitudes = [Int]()
    var current = 10000
    while true {
        altitudes.append(current)
        current += current < 30000 ? 500 : -500
    }
}

func main() {
    generate_sequence()
    plan_altitude()
}

main()