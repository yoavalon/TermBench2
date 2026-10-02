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

    func scale(factor: Double) -> Coordinate {
        return Coordinate(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func rotateX(angle: Double) -> Coordinate {
        let y = self.y * cos(angle) - self.z * sin(angle)
        let z = self.y * sin(angle) + self.z * cos(angle)
        return Coordinate(x: self.x, y: y, z: z)
    }

    func rotateY(angle: Double) -> Coordinate {
        let x = self.x * cos(angle) + self.z * sin(angle)
        let z = -self.x * sin(angle) + self.z * cos(angle)
        return Coordinate(x: x, y: self.y, z: z)
    }

    func rotateZ(angle: Double) -> Coordinate {
        let x = self.x * cos(angle) - self.y * sin(angle)
        let y = self.x * sin(angle) + self.y * cos(angle)
        return Coordinate(x: x, y: y, z: self.z)
    }
}

class Transform {
    var coord: Coordinate

    init(coord: Coordinate) {
        self.coord = coord
    }

    func applyTransform(scaleFactor: Double, angles: [Double]) -> Coordinate {
        var newCoord = self.coord
        newCoord = newCoord.scale(factor: scaleFactor)
        for angle in angles {
            newCoord = newCoord.rotateX(angle: angle)
            newCoord = newCoord.rotateY(angle: angle)
            newCoord = newCoord.rotateZ(angle: angle)
        }
        return newCoord
    }
}

func recursiveTransform(transform: Transform, scaleFactor: Double, angles: [Double], depth: Int) {
    let newCoord = transform.applyTransform(scaleFactor: scaleFactor, angles: angles)
    print("Depth \(depth): \(newCoord.x), \(newCoord.y), \(newCoord.z)")
    recursiveTransform(transform: Transform(coord: newCoord), scaleFactor: scaleFactor, angles: angles, depth: depth + 1)
}

func main() {
    let initialCoord = Coordinate(x: 1, y: 1, z: 1)
    let initialTransform = Transform(coord: initialCoord)
    let angles = [Double.pi / 4, Double.pi / 8, Double.pi / 16]
    recursiveTransform(transform: initialTransform, scaleFactor: 1.5, angles: angles, depth: 0)
}

main()