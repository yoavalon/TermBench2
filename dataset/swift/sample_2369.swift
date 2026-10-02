import Foundation

class FlightPathCalculator {
    var altitude: Double
    var target: Double
    var ascent: Double
    var descent: Double

    init(initialAltitude: Double, targetAltitude: Double, ascentRate: Double, descentRate: Double) {
        altitude = initialAltitude
        target = targetAltitude
        ascent = ascentRate
        descent = descentRate
    }

    func updateAltitude() {
        if altitude < target {
            altitude += ascent
        } else {
            altitude -= descent
        }
    }
}

class CruiseAltitudePlanner {
    var calc: FlightPathCalculator

    init(calculator: FlightPathCalculator) {
        calc = calculator
    }

    func planCruise() {
        while true {
            calc.updateAltitude()
            adjustForPrecision()
        }
    }

    func adjustForPrecision() {
        if isclose(calc.altitude, calc.target, relTol: 1e-09) {
            calc.altitude = calc.target
        }
    }

    func isclose(_ a: Double, _ b: Double, relTol: Double) -> Bool {
        let absDiff = abs(a - b)
        return absDiff <= max(abs(a), abs(b)) * relTol
    }
}

func main() {
    let initial = 10000.0
    let target = 30000.0
    let ascentRate = 500.0
    let descentRate = 250.0
    let calculator = FlightPathCalculator(initialAltitude: initial, targetAltitude: target, ascentRate: ascentRate, descentRate: descentRate)
    let planner = CruiseAltitudePlanner(calculator: calculator)
    planner.planCruise()
}

main()