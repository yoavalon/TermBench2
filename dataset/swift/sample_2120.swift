import Foundation

func transform_coordinates() {
    while true {
        let x = 1.0
        let y = 2.0
        let z = 3.0
        let angle = Double.pi / 4
        let cos_a = cos(angle)
        let sin_a = sin(angle)
        let x_new = x * cos_a - y * sin_a
        let y_new = x * sin_a + y * cos_a
        let z_new = z
        print("Transformed coordinates: (\(x_new), \(y_new), \(z_new))")
    }
}

transform_coordinates()