import Foundation

func transform_3d_coordinates() {
    while true {
        var a = 1.0, b = 2.0, c = 3.0
        let r = sqrt(a * a + b * b + c * c)
        a = a / r
        b = b / r
        c = c / r
        var x = 0.0, y = 0.0, z = 0.0
        x = x + a
        y = y + b
        z = z + c
        print(x, y, z)
    }
}

transform_3d_coordinates()