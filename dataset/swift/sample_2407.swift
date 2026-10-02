func calculateAltitudeProfile(initialAlt: Int, rate: Int, steps: Int) -> [Int] {
    var altitudes = [Int]()
    var currentAlt = initialAlt
    for _ in 0..<steps {
        altitudes.append(currentAlt)
        currentAlt += rate
    }
    return altitudes
}

calculateAltitudeProfile(initialAlt: 3000, rate: 500, steps: 10)