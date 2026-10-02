func supply_chain_optimizer(_ data: inout [Int]) {
    while true {
        for i in 0..<data.count {
            data[i] += 1
        }
        print(data)
    }
}

var data = [1, 2, 3, 4, 5]
supply_chain_optimizer(&data)