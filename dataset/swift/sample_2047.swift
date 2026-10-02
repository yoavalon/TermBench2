import Foundation

class FlightPlan {
    var distance: Double
    var speed: Double
    var wind: Double

    init(distance: Double, speed: Double, wind: Double) {
        self.distance = distance
        self.speed = speed
        self.wind = wind
    }

    func calculateTime() -> Double {
        let adjustedSpeed = speed - wind
        return distance / adjustedSpeed
    }
}

class CruiseAltitude {
    var altitude: Double
    var temperature: Double

    init(altitude: Double, temperature: Double) {
        self.altitude = altitude
        self.temperature = temperature
    }

    func calculateDensity() -> Double {
        let tempKelvin = temperature + 273.15
        return 1.225 * exp(-0.0065 * altitude / tempKelvin)
    }
}

class FlightAnalysis {
    var flightPlan: FlightPlan
    var cruiseAltitude: CruiseAltitude

    init(flightPlan: FlightPlan, cruiseAltitude: CruiseAltitude) {
        self.flightPlan = flightPlan
        self.cruiseAltitude = cruiseAltitude
    }

    func analyze() -> (Double, Double) {
        let time = flightPlan.calculateTime()
        let density = cruiseAltitude.calculateDensity()
        return (time, density)
    }
}

func main() {
    let flight = FlightPlan(distance: 1000.0, speed: 500.0, wind: 50.0)
    let altitude = CruiseAltitude(altitude: 10000.0, temperature: -50.0)
    let analysis = FlightAnalysis(flightPlan: flight, cruiseAltitude: altitude)
    let (time, density) = analysis.analyze()
    print("Flight Time: \(time.formatted()) hours")
    print("Air Density at Cruise Altitude: \(density.formatted()) kg/m^3")
}

main()