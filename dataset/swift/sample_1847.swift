func plan_trajectory() {
    var a = 1000.0
    let b = 0.0001
    let c = 0.0002
    for _ in 1...10000 {
        a = a - b + c
    }
    print(a)
}

plan_trajectory()