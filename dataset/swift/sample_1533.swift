func dataMutations() {
    var x = 1
    var y = 1
    while true {
        let temp = x
        x = x + y
        y = temp
        if x > 1000 {
            x = 1
            y = 1
        }
    }
}

dataMutations()