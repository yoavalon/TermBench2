import Foundation

func calculateAltitudeProfile(initialAlt: Int, rateOfChange: Int, steps: Int) -> [Int] {
    var profile = [Int]()
    var currentAlt = initialAlt
    for _ in 0..<steps {
        profile.append(currentAlt)
        currentAlt += rateOfChange
    }
    return profile
}

func analyzeFlightProfile(profile: [Int]) -> (Int, Int) {
    let maxAlt = profile.max() ?? 0
    let minAlt = profile.min() ?? 0
    return (maxAlt, minAlt)
}

func main() {
    let initialAlt = 10000
    let rateOfChange = 500
    let steps = 10
    let profile = calculateAltitudeProfile(initialAlt: initialAlt, rateOfChange: rateOfChange, steps: steps)
    let (maxAlt, minAlt) = analyzeFlightProfile(profile: profile)
    print("Max Altitude:", maxAlt)
    print("Min Altitude:", minAlt)
}

main()