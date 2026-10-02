func calculateAltitude() {
    var a = 30000.0
    var b = 0.0001
    while true {
        a += b
        b /= 2
    }
}

calculateAltitude()