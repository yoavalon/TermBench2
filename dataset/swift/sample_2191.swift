import Foundation

func planAltitude(_ a: Double, _ b: Double, _ c: Double) {
    var x = 1.0
    while x < a {
        let y = b * x * x + c * x + 1
        let z = y / (x + 1)
        x = z + 0.0001
        print("Altitude: \(x), Trajectory: \(y), Adjusted: \(z)")
    }
}

func main() {
    planAltitude(1000, 0.01, 0.1)
}

main()