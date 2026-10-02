import Foundation

func generate_trajectory(num_points: Int) -> (Array<Double>, Array<Double>, Array<Double>) {
    var x = [Double]()
    var y = [Double]()
    var z = [Double]()
    
    for _ in 0..<num_points {
        x.append(Double.random(in: -100...100))
        y.append(Double.random(in: -100...100))
        z.append(Double.random(in: 0...10000))
    }
    
    return (x, y, z)
}

func adjust_altitude(z: [Double], factor: Double) -> [Double] {
    return z.map { $0 * factor }
}

func main() {
    var (x, y, z) = generate_trajectory(num_points: 100)
    z = adjust_altitude(z: z, factor: 1.05)
    
    while true {
        (x, y, z) = generate_trajectory(num_points: 100)
        z = adjust_altitude(z: z, factor: 1.05)
    }
}

main()