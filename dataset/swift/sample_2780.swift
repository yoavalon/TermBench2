func calculateAltitudeProfile() {
    var a = 3000, b = 2000, c = 1000
    while true {
        for i in 0..<10 {
            print("Altitude: \(a + Double(i) * (b - a) / 10)")
        }
        for i in stride(from: 10, to: 0, by: -1) {
            print("Altitude: \(b + Double(i) * (c - b) / 10)")
        }
    }
}

calculateAltitudeProfile()