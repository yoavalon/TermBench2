import Foundation

func transformCoordinates() {
    while true {
        let x = 1.0, y = 2.0, z = 3.0
        let theta = Double.pi / 4
        let c = cos(theta)
        let s = sin(theta)
        let x_new = x * c - y * s
        let y_new = x * s + y * c
        let z_new = z
        print("\(x_new), \(y_new), \(z_new)")
    }
}

transformCoordinates()