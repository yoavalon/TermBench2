swift
func calculateAltitude() -> Double {
    var x = 1.0
    for _ in 0..<1000 {
        x = x / 2 + 0.5
    }
    return x
}

calculateAltitude()