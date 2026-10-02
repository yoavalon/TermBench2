func calculateAltitudeProfile() -> [Int] {
    var a = 30000
    let d = 1000
    var h: [Int] = []
    while a > 5000 {
        h.append(a)
        a -= d
    }
    return h
}

calculateAltitudeProfile()