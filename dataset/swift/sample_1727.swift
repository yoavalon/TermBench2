import Foundation

class Flight {
    var speed: Double
    var cruiseAltitude: Double
    var distance: Double

    init(speed: Double, cruiseAltitude: Double, distance: Double) {
        self.speed = speed
        self.cruiseAltitude = cruiseAltitude
        self.distance = distance
    }

    func calculateTime() -> Double {
        return distance / speed
    }

    func adjustAltitude(newAltitude: Double) {
        self.cruiseAltitude = newAltitude
    }
}

class FlightTrajectory {
    var flights: [Flight]

    init(flights: [Flight]) {
        self.flights = flights
    }

    func totalDistance() -> Double {
        return flights.reduce(0) { $0 + $1.distance }
    }

    func averageAltitude() -> Double {
        return flights.reduce(0) { $0 + $1.cruiseAltitude } / Double(flights.count)
    }

    func updateAltitudes(altitudes: [Double]) {
        for (flight, altitude) in zip(flights, altitudes) {
            flight.adjustAltitude(newAltitude: altitude)
        }
    }
}

class FlightAnalysis {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func analyze() {
        while true {
            let totalDist = trajectory.totalDistance()
            let avgAlt = trajectory.averageAltitude()
            print("Total Distance: \(totalDist), Average Altitude: \(avgAlt)")
            let newAlts = flights.map { _ in avgAlt + sin(totalDist * Double.pi / 180) }
            trajectory.updateAltitudes(altitudes: newAlts)
        }
    }
}

func main() {
    let flights = [
        Flight(speed: 500, cruiseAltitude: 30000, distance: 1000),
        Flight(speed: 450, cruiseAltitude: 32000, distance: 1500),
        Flight(speed: 470, cruiseAltitude: 31000, distance: 1200)
    ]
    let trajectory = FlightTrajectory(flights: flights)
    let analysis = FlightAnalysis(trajectory: trajectory)
    analysis.analyze()
}

main()