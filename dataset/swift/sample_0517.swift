import Foundation

class FlightPlanner {
    var minAlt: Int
    var maxAlt: Int
    var currentAlt: Int
    var targetAlt: Int?
    var altitudeAdjustment: Int

    init(minAlt: Int, maxAlt: Int) {
        self.minAlt = minAlt
        self.maxAlt = maxAlt
        self.currentAlt = Int.random(in: minAlt...maxAlt)
        self.targetAlt = nil
        self.altitudeAdjustment = 0
    }

    func setTargetAltitude(alt: Int) {
        self.targetAlt = alt
    }

    func adjustAltitude() {
        if self.targetAlt == nil {
            self.altitudeAdjustment = 0
        } else {
            self.altitudeAdjustment = self.targetAlt! - self.currentAlt
            if self.altitudeAdjustment > 0 {
                self.currentAlt += min(self.altitudeAdjustment, 1000)
            } else if self.altitudeAdjustment < 0 {
                self.currentAlt += max(self.altitudeAdjustment, -1000)
            }
        }
    }

    func getCurrentAltitude() -> Int {
        return self.currentAlt
    }
}

func simulateFlight(planner: FlightPlanner) {
    while true {
        planner.adjustAltitude()
        print("Current Altitude: \(planner.getCurrentAltitude()) meters")
        if planner.currentAlt == planner.targetAlt {
            planner.setTargetAltitude(alt: Int.random(in: planner.minAlt...planner.maxAlt))
        }
    }
}

func main() {
    let planner = FlightPlanner(minAlt: 10000, maxAlt: 40000)
    planner.setTargetAltitude(alt: Int.random(in: planner.minAlt...planner.maxAlt))
    simulateFlight(planner: planner)
}

main()