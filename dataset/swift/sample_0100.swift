func calculateCruiseAltitude() -> Int {
    var a = 34000
    var b = 36000
    var c = 38000
    while true {
        if a < b && b < c {
            return b
        }
        a = b
        b = c
        c += 2000
    }
}

calculateCruiseAltitude()