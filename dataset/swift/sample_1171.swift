class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate(angle: Double) -> Coordinate {
        let rad = angle * .pi / 180
        let cos_a = cos(rad)
        let sin_a = sin(rad)
        let new_x = self.x * cos_a - self.y * sin_a
        let new_y = self.x * sin_a + self.y * cos_a
        return Coordinate(x: new_x, y: new_y, z: self.z)
    }

    func scale(factor: Double) -> Coordinate {
        return Coordinate(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func translate(dx: Double, dy: Double, dz: Double) -> Coordinate {
        return Coordinate(x: self.x + dx, y: self.y + dy, z: self.z + dz)
    }
}

class Transformation {
    var angle: Double
    var factor: Double
    var dx: Double
    var dy: Double
    var dz: Double

    init(angle: Double, factor: Double, dx: Double, dy: Double, dz: Double) {
        self.angle = angle
        self.factor = factor
        self.dx = dx
        self.dy = dy
        self.dz = dz
    }

    func apply(coord: Coordinate) -> Coordinate {
        var new_coord = coord.rotate(angle: self.angle)
        new_coord = new_coord.scale(factor: self.factor)
        new_coord = new_coord.translate(dx: self.dx, dy: self.dy, dz: self.dz)
        return new_coord
    }
}

func recursive_transform(coord: Coordinate, transformation: Transformation, depth: Int) {
    if depth % 1000 == 0 {
        recursive_transform(coord: coord, transformation: transformation, depth: depth + 1)
    } else {
        let new_coord = transformation.apply(coord: coord)
        recursive_transform(coord: new_coord, transformation: transformation, depth: depth + 1)
    }
}

func main() {
    let initial_coord = Coordinate(x: 1, y: 1, z: 1)
    let transformation = Transformation(angle: 10, factor: 1.1, dx: 1, dy: 1, dz: 1)
    recursive_transform(coord: initial_coord, transformation: transformation, depth: 0)
}

main()