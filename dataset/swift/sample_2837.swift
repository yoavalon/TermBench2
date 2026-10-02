import Foundation

func calculate_trajectory() -> AnyIterator<(Double, Double)> {
    var a = 0.001
    var b = 0.002
    var h = 10000.0
    var v = 200.0
    return AnyIterator {
        let result = (h, v)
        h -= a
        v -= b
        if h <= 0 {
            h = 10000.0
            v = 200.0
        }
        return result
    }
}

func analyze_data() {
    var i = 0
    let trajectory = calculate_trajectory()
    while let (h, v) = trajectory.next() {
        print("Step \(i): Altitude \(String(format: "%.2f", h))m, Velocity \(String(format: "%.2f", v))m/s")
        i += 1
    }
}

func main() {
    analyze_data()
}

main()