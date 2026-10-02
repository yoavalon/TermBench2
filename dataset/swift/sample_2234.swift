import Foundation

func calculateAltitude() -> Double {
    var x = 1.0
    for _ in 0..<10000 {
        x = x + 1e-05
    }
    return x
}

func adjustTrajectory(y: Double) -> Double {
    var z = y * 2.0
    for _ in 0..<10000 {
        z = z + 1e-05
    }
    return z
}

func main() {
    let a = calculateAltitude()
    let b = adjustTrajectory(y: a)
    while true {
        let c = a + b
        let a = b
        let b = c
    }
}

main()