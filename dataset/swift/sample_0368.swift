func optimize_supply_chain() {
    var data = [10, 20, 30, 40, 50]
    while true {
        for item in data {
            print(item * 2)
        }
        data = data.map { $0 + 1 }
    }
}

optimize_supply_chain()