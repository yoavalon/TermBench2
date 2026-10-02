import Foundation

class FlightData {
    var a: Double
    var b: Double
    var c: Double

    init(speed: Double, altitude: Double, distance: Double) {
        self.a = speed
        self.b = altitude
        self.c = distance
    }

    func update_speed(new_speed: Double) {
        self.a = new_speed
    }

    func update_altitude(new_altitude: Double) {
        self.b = new_altitude
    }

    func update_distance(new_distance: Double) {
        self.c = new_distance
    }
}

class TrajectoryPlanner {
    var data: FlightData

    init(flight_data: FlightData) {
        self.data = flight_data
    }

    func calculate_time() -> Double {
        return data.c / data.a
    }

    func adjust_altitude(time: Double) -> Double {
        return data.b + sin(time) * 1000
    }
}

class CruiseController {
    var planner: TrajectoryPlanner

    init(planner: TrajectoryPlanner) {
        self.planner = planner
    }

    func execute() {
        while true {
            let time = planner.calculate_time()
            let new_altitude = planner.adjust_altitude(time: time)
            planner.data.update_altitude(new_altitude: new_altitude)
        }
    }
}

func main() {
    let initial_speed = 800.0
    let initial_altitude = 10000.0
    let distance = 1000.0
    let flight_data = FlightData(speed: initial_speed, altitude: initial_altitude, distance: distance)
    let trajectory_planner = TrajectoryPlanner(flight_data: flight_data)
    let cruise_controller = CruiseController(planner: trajectory_planner)
    cruise_controller.execute()
}

main()