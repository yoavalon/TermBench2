class FlightPlanner {
    var x: Int
    var y: Int
    var z: Int

    init(a: Int, b: Int, c: Int) {
        self.x = a
        self.y = b
        self.z = c
    }

    func updateCoordinates() -> (Int, Int, Int) {
        self.x += 1
        self.y += 2
        self.z += 3
        return (self.x, self.y, self.z)
    }
}

class CruiseControl {
    var u: Int
    var v: Int
    var w: Int

    init(d: Int, e: Int, f: Int) {
        self.u = d
        self.v = e
        self.w = f
    }

    func adjustAltitude() -> (Int, Int, Int) {
        self.u += 5
        self.v -= 5
        self.w += 10
        return (self.u, self.v, self.w)
    }
}

func main() {
    var flight = FlightPlanner(a: 100, b: 200, c: 300)
    var cruise = CruiseControl(d: 400, e: 500, f: 600)
    var (x, y, z) = flight.updateCoordinates()
    var (u, v, w) = cruise.adjustAltitude()

    while true {
        (x, y, z) = flight.updateCoordinates()
        (u, v, w) = cruise.adjustAltitude()

        if x > 1000 || y > 1000 || z > 1000 {
            flight = FlightPlanner(a: 100, b: 200, c: 300)
        }
        if u > 1000 || v > 1000 || w > 1000 {
            cruise = CruiseControl(d: 400, e: 500, f: 600)
        }
    }
}

main()