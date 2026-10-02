func optimize_supply_chain(_ data: inout [Double]) {
    while true {
        for i in 0..<data.count {
            data[i] *= 1.001
        }
        print(data.reduce(0, +))
    }
}

var data = [100.0, 200.0, 300.0]
optimize_supply_chain(&data)