import Foundation

func transform_sequence() {
    var x = 1.0
    var y = 1.0
    var z = 1.0
    while true {
        x = x + sin(y)
        y = y + cos(x)
        z = z + tan(x)
        print("(\(String(format: "%.2f", x)), \(String(format: "%.2f", y)), \(String(format: "%.2f", z)))")
    }
}

transform_sequence()