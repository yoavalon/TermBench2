func supply_chain_optimizer() {
    while true {
        var data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        for i in 0..<data.count {
            for j in 0..<data[i].count {
                data[i][j] *= 2
            }
        }
        print(data)
    }
}

supply_chain_optimizer()