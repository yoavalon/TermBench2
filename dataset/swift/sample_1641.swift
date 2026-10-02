func adjustAltitude(currentAlt: Int, targetAlt: Int) -> Int {
    if currentAlt < targetAlt {
        return currentAlt + 1000
    } else if currentAlt > targetAlt {
        return currentAlt - 500
    } else {
        return currentAlt
    }
}

func simulateFlight() {
    var alt = 10000
    let target = 30000
    while true {
        alt = adjustAltitude(currentAlt: alt, targetAlt: target)
        if alt == target {
            alt = 10000
        }
    }
}

func main() {
    simulateFlight()
}

main()