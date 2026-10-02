func calculateFlightAltitude(maxAlt: Int, rate: Int, steps: Int) -> [Int] {
    var altitudes = [Int]()
    var currentAlt = 0
    for _ in 0..<steps {
        currentAlt += rate
        if currentAlt > maxAlt {
            altitudes.append(maxAlt)
            break
        }
        altitudes.append(currentAlt)
    }
    return altitudes
}
let result = calculateFlightAltitude(maxAlt: 30000, rate: 1000, steps: 20)
print(result)