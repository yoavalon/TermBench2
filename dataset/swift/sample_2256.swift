import Foundation

func calculateAltitude(time: Double) -> Double {
    let g = 9.80665
    let v0 = 150.0
    let h0 = 10000.0
    return h0 - 0.5 * g * time * time + v0 * time
}

func adjustTrajectory(currentTime: Int, targetAltitude: Double) -> Int {
    let currentAltitude = calculateAltitude(time: Double(currentTime))
    let altitudeDifference = targetAltitude - currentAltitude
    if abs(altitudeDifference) < 100 {
        return currentTime
    }
    return adjustTrajectory(currentTime: currentTime + 1, targetAltitude: targetAltitude)
}

func main() {
    let target = 5000.0
    let startTime = 0
    let finalTime = adjustTrajectory(currentTime: startTime, targetAltitude: target)
    print(finalTime)
}

main()