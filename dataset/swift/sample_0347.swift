func simulate() {
    var data = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
    while true {
        for i in 0..<data.count {
            data[i] = (data[i] + 0.01) % 1.0
            print(data)
        }
    }
}

simulate()