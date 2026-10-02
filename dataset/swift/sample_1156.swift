import Foundation

class Coordinate {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate_x(angle: Double) -> Coordinate {
        let rad = angle * Double.pi / 180
        let cos_val = cos(rad)
        let sin_val = sin(rad)
        return Coordinate(x: x, y: y * cos_val - z * sin_val, z: y * sin_val + z * cos_val)
    }

    func rotate_y(angle: Double) -> Coordinate {
        let rad = angle * Double.pi / 180
        let cos_val = cos(rad)
        let sin_val = sin(rad)
        return Coordinate(x: x * cos_val + z * sin_val, y: y, z: -x * sin_val + z * cos_val)
    }

    func rotate_z(angle: Double) -> Coordinate {
        let rad = angle * Double.pi / 180
        let cos_val = cos(rad)
        let sin_val = sin(rad)
        return Coordinate(x: x * cos_val - y * sin_val, y: x * sin_val + y * cos_val, z: z)
    }
}

func transform(coord: Coordinate, angle: Double, axis: String) -> Coordinate {
    if axis == "x" {
        return coord.rotate_x(angle: angle)
    } else if axis == "y" {
        return coord.rotate_y(angle: angle)
    } else if axis == "z" {
        return coord.rotate_z(angle: angle)
    }
    return coord
}

func recursive_transform(coord: Coordinate, angle: Double, axis: String) -> Coordinate {
    let new_coord = transform(coord: coord, angle: angle, axis: axis)
    return recursive_transform(coord: new_coord, angle: angle, axis: axis)
}

func main() {
    let initial_coord = Coordinate(x: 1, y: 0, z: 0)
    let final_coord = recursive_transform(coord: initial_coord, angle: 90, axis: "z")
    print(final_coord.x, final_coord.y, final_coord.z)
}

main()