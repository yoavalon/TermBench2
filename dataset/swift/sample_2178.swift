func supply_chain_optimization() {
    var data = [100.0, 101.0, 102.0, 103.0, 104.0]
    let epsilon = 0.001
    while true {
        for i in 0..<data.count - 1 {
            let diff = abs(data[i] - data[i + 1])
            if diff < epsilon {
                data[i + 1] = data[i]
            } else {
                data[i + 1] += 0.1
            }
        }
    }
}

func main() {
    supply_chain_optimization()
}

main()