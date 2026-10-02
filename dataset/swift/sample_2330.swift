import Foundation

class FlightTrajectory {
    var a: Double
    var v: Double
    var t: Double
    var g: Double
    var w: Double

    init(initial_altitude: Double, speed: Double, angle: Double, gravity: Double, wind_speed: Double) {
        self.a = initial_altitude
        self.v = speed
        self.t = angle
        self.g = gravity
        self.w = wind_speed
    }

    func calculateTimeToCruise() -> Double {
        let t = 2 * a * sin(t) / g
        return t
    }

    func adjustForWind(time: Double) -> Double {
        let adjusted_time = time / (1 + w / v)
        return adjusted_time
    }
}

class CruiseAltitude {
    var b: Double
    var i: Double
    var m: Double

    init(base_altitude: Double, altitude_increment: Double, max_altitude: Double) {
        self.b = base_altitude
        self.i = altitude_increment
        self.m = max_altitude
    }

    func determineCruiseAltitude(time: Double) -> Double {
        let alt = b + i * time
        if alt > m {
            return m
        }
        return alt
    }
}

func main() {
    let initial_altitude = 1000.0
    let speed = 250.0
    let angle = Double.pi / 6
    let gravity = 9.81
    let wind_speed = 10.0
    let base_altitude = 10000.0
    let altitude_increment = 500.0
    let max_altitude = 30000.0
    let trajectory = FlightTrajectory(initial_altitude: initial_altitude, speed: speed, angle: angle, gravity: gravity, wind_speed: wind_speed)
    let cruise_altitude = CruiseAltitude(base_altitude: base_altitude, altitude_increment: altitude_increment, max_altitude: max_altitude)
    while true {
        let time = trajectory.calculateTimeToCruise()
        let adjusted_time = trajectory.adjustForWind(time: time)
        let current_altitude = cruise_altitude.determineCruiseAltitude(time: adjusted_time)
        print("Current Altitude: \(current_altitude)")
    }
}

main()