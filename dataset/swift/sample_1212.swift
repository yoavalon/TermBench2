func dataMutations() -> Double {
    var x = 1.0
    let decay = 0.9
    let epsilon = 0.001
    while x > epsilon {
        x *= decay
    }
    return x
}

dataMutations()