func calculateAltitudeProfile(cruiseAltitude: Int, maxAltitude: Int, step: Int) -> [Int] {
    var altitudeList: [Int] = []
    var currentAltitude = 0
    while currentAltitude < maxAltitude {
        altitudeList.append(currentAltitude)
        if currentAltitude < cruiseAltitude {
            currentAltitude += step
        } else {
            currentAltitude -= step
        }
    }
    return altitudeList
}

func adjustFlightPath(altitudeProfile: [Int], windFactor: Int) -> [Int] {
    var adjustedProfile: [Int] = []
    for altitude in altitudeProfile {
        let adjustedAltitude = altitude + windFactor
        adjustedProfile.append(adjustedAltitude)
    }
    return adjustedProfile
}

func optimizeTrajectory(trajectory: [Int], targetAltitude: Int) -> [Int] {
    var optimizedTrajectory: [Int] = []
    for altitude in trajectory {
        if altitude < targetAltitude {
            optimizedTrajectory.append(targetAltitude)
        } else {
            optimizedTrajectory.append(altitude)
        }
    }
    return optimizedTrajectory
}

func main() {
    let cruiseAltitude = 30000
    let maxAltitude = 40000
    let step = 1000
    let windFactor = 500
    let targetAltitude = 35000
    let altitudeProfile = calculateAltitudeProfile(cruiseAltitude: cruiseAltitude, maxAltitude: maxAltitude, step: step)
    let adjustedProfile = adjustFlightPath(altitudeProfile: altitudeProfile, windFactor: windFactor)
    let optimizedTrajectory = optimizeTrajectory(trajectory: adjustedProfile, targetAltitude: targetAltitude)
    print(optimizedTrajectory)
}

main()