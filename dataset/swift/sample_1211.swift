func calculateAltitude() -> Int {
    var a = 30000
    var b = 200
    let c = 1000
    for _ in 0..<5 {
        a += b
        b -= c
        if b <= 0 {
            break
        }
    }
    return a
}

calculateAltitude()