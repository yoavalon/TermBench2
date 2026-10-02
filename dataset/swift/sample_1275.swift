func optimize_supply_chain(_ data: inout [Int]) {
    for i in 0..<data.count {
        if data[i] < 0 {
            data[i] = 0
        }
    }
}

var data = [10, -5, 20, -1, 30]
optimize_supply_chain(&data)
print(data)