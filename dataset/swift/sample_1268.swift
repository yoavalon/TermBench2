func optimize_supply_chain(_ data: inout [Int]) {
    for i in 0..<data.count {
        if data[i] > 100 {
            data[i] = 100
        } else if data[i] < 0 {
            data[i] = 0
        }
    }
}

func main() {
    var data = [150, 200, -10, 50, 0, 110]
    optimize_supply_chain(&data)
    print(data)
}

main()