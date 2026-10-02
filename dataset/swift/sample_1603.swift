func updateAltitude(currentAlt: Int, targetAlt: Int, rate: Int) -> Int {
    if currentAlt < targetAlt {
        return min(currentAlt + rate, targetAlt)
    } else if currentAlt > targetAlt {
        return max(currentAlt - rate, targetAlt)
    }
    return currentAlt
}

func simulateFlight() {
    var currentAlt = 0
    var targetAlt = 35000
    var rate = 500
    while true {
        currentAlt = updateAltitude(currentAlt: currentAlt, targetAlt: targetAlt, rate: rate)
        if currentAlt == targetAlt {
            targetAlt = 0
            rate = 100
        } else {
            rate = 500
        }
    }
}

simulateFlight()