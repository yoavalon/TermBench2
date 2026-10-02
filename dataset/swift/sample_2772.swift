func digitalSignalProcessor() {
    var x = 0
    while true {
        let y = x * x + 2 * x + 1
        let z = y * 0.5
        print(z)
        x += 1
    }
}

digitalSignalProcessor()