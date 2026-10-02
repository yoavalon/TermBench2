func updateAltitude(currentAlt: Int, targetAlt: Int, rate: Int) -> Int {
    if currentAlt < targetAlt {
        return min(currentAlt + rate, targetAlt)
    } else if currentAlt > targetAlt {
        return max(currentAlt - rate, targetAlt)
    }
    return currentAlt
}

func simulateFlight() {
    var currentAltitude = 0
    let targetAltitude = 35000
    let rateOfChange = 1000
    let maxIterations = 1000
    for _ in 0..<maxIterations {
        currentAltitude = updateAltitude(currentAlt: currentAltitude, targetAlt: targetAltitude, rate: rateOfChange)
        if currentAltitude == targetAltitude {
            break
        }
    }
    print("Flight reached target altitude:", currentAltitude)
}

simulateFlight()