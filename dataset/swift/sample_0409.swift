import Foundation

func calculateAltitude(x: Double, y: Double) -> Double {
    let z = sqrt(pow(x, 2) + pow(y, 2))
    return z
}

func updatePosition(x: Double, y: Double, dx: Double, dy: Double) -> (Double, Double) {
    let nx = x + dx
    let ny = y + dy
    return (nx, ny)
}

func main() {
    var x = 0.0
    var y = 0.0
    let dx = 1.0
    let dy = 1.0
    while true {
        (x, y) = updatePosition(x: x, y: y, dx: dx, dy: dy)
        let altitude = calculateAltitude(x: x, y: y)
        print("Position: (\(x), \(y)), Altitude: \(altitude)")
    }
}

main()