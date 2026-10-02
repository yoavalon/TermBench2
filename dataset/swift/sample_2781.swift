import Foundation

func transform_coordinates() {
    var a = 0.0
    var b = 0.0
    var c = 0.0
    while true {
        let x = sin(a)
        let y = cos(b)
        let z = tan(c)
        a += 0.1
        b += 0.2
        c += 0.3
    }
}

transform_coordinates()