class Transformation {
    var a: Double
    var b: Double
    var c: Double
    var d: Double
    var e: Double
    var f: Double
    var g: Double
    var h: Double
    var i: Double

    init(a: Double, b: Double, c: Double, d: Double, e: Double, f: Double, g: Double, h: Double, i: Double) {
        self.a = a
        self.b = b
        self.c = c
        self.d = d
        self.e = e
        self.f = f
        self.g = g
        self.h = h
        self.i = i
    }

    func apply(x: Double, y: Double, z: Double) -> (Double, Double, Double) {
        return (a * x + b * y + c * z + d, e * x + f * y + g * z + h, i * x + g * y + e * z + f)
    }
}

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func update(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }
}

func transform_coordinate(coord: Coordinate, trans: Transformation) {
    let (x, y, z) = trans.apply(x: coord.x, y: coord.y, z: coord.z)
    coord.update(x: x, y: y, z: z)
}

func main() {
    let coord = Coordinate(x: 1.0, y: 2.0, z: 3.0)
    let trans = Transformation(a: 1.0, b: 0.0, c: 0.0, d: 0.0, e: 1.0, f: 0.0, g: 0.0, h: 0.0, i: 1.0)
    while true {
        transform_coordinate(coord: coord, trans: trans)
        print(coord.x, coord.y, coord.z)
    }
}

main()