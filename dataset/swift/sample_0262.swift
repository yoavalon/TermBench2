class FlightPlanner {
    var altitude: Int
    var maxSpeed: Int
    var position: Int

    init(altitude: Int, maxSpeed: Int, initialPosition: Int) {
        self.altitude = altitude
        self.maxSpeed = maxSpeed
        self.position = initialPosition
    }

    func updateAltitude(newAltitude: Int) {
        if 0 < newAltitude && newAltitude <= 10000 {
            self.altitude = newAltitude
        }
    }

    func adjustSpeed(newSpeed: Int) {
        if 0 < newSpeed && newSpeed <= 800 {
            self.maxSpeed = newSpeed
        }
    }

    func navigate(targetPosition: Int) {
        let distance = abs(targetPosition - self.position)
        let speed = min(distance, self.maxSpeed)
        self.position += targetPosition > self.position ? speed : -speed
    }
}

func main() {
    let planner = FlightPlanner(altitude: 5000, maxSpeed: 600, initialPosition: 0)
    planner.updateAltitude(newAltitude: 7000)
    planner.adjustSpeed(newSpeed: 500)
    planner.navigate(targetPosition: 10000)
    planner.navigate(targetPosition: 5000)
    planner.updateAltitude(newAltitude: 3000)
    planner.adjustSpeed(newSpeed: 300)
    planner.navigate(targetPosition: 0)
    planner.navigate(targetPosition: 2000)
    planner.updateAltitude(newAltitude: 6000)
    planner.adjustSpeed(newSpeed: 400)
    planner.navigate(targetPosition: 8000)
    planner.navigate(targetPosition: 12000)
    planner.updateAltitude(newAltitude: 8000)
    planner.adjustSpeed(newSpeed: 200)
    planner.navigate(targetPosition: 15000)
    planner.navigate(targetPosition: 10000)
    planner.updateAltitude(newAltitude: 4000)
    planner.adjustSpeed(newSpeed: 100)
    planner.navigate(targetPosition: 5000)
    planner.navigate(targetPosition: 0)
    print("Final position:", planner.position)
}

main()