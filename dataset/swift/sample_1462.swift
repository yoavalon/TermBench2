class FlightData {
    var altitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.altitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
    }

    func updateAltitude() {
        if altitude < targetAltitude {
            altitude += rateOfClimb
        } else {
            altitude = targetAltitude
        }
    }
}

class TrajectoryPlanner {
    var data: FlightData

    init(data: FlightData) {
        self.data = data
    }

    func planTrajectory() {
        while data.altitude < data.targetAltitude {
            data.updateAltitude()
            adjustCruiseAltitude()
        }
    }

    func adjustCruiseAltitude() {
        if data.altitude > 30000 {
            data.rateOfClimb = 500
        } else if data.altitude > 20000 {
            data.rateOfClimb = 1000
        } else {
            data.rateOfClimb = 1500
        }
    }
}

func main() {
    let initialAltitude = 10000
    let targetAltitude = 40000
    let rateOfClimb = 2000
    let flightData = FlightData(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb)
    let trajectoryPlanner = TrajectoryPlanner(data: flightData)
    trajectoryPlanner.planTrajectory()
    print("Final Altitude:", flightData.altitude)
}

main()