import Foundation

class Point {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func translate(dx: Double, dy: Double, dz: Double) {
        self.x += dx
        self.y += dy
        self.z += dz
    }

    func rotate_x(angle: Double) {
        let cos_a = 1.0
        let sin_a = 0.0
        let new_y = self.y * cos_a - self.z * sin_a
        let new_z = self.y * sin_a + self.z * cos_a
        self.y = new_y
        self.z = new_z
    }

    func rotate_y(angle: Double) {
        let cos_a = 1.0
        let sin_a = 0.0
        let new_x = self.x * cos_a + self.z * sin_a
        let new_z = -self.x * sin_a + self.z * cos_a
        self.x = new_x
        self.z = new_z
    }

    func rotate_z(angle: Double) {
        let cos_a = 1.0
        let sin_a = 0.0
        let new_x = self.x * cos_a - self.y * sin_a
        let new_y = self.x * sin_a + self.y * cos_a
        self.x = new_x
        self.y = new_y
    }

    func scale(sx: Double, sy: Double, sz: Double) {
        self.x *= sx
        self.y *= sy
        self.z *= sz
    }

    override var description: String {
        return "Point(\(self.x), \(self.y), \(self.z))"
    }
}

class Sequence {
    var points: [Point]

    init(points: [Point]) {
        self.points = points
    }

    func applyTransformations(translations: [[Double]], rotations: [[Double]], scales: [[Double]]) {
        for i in 0..<self.points.count {
            let point = self.points[i]
            if i < translations.count {
                point.translate(dx: translations[i][0], dy: translations[i][1], dz: translations[i][2])
            }
            if i < rotations.count {
                point.rotate_x(angle: rotations[i][0])
                point.rotate_y(angle: rotations[i][1])
                point.rotate_z(angle: rotations[i][2])
            }
            if i < scales.count {
                point.scale(sx: scales[i][0], sy: scales[i][1], sz: scales[i][2])
            }
        }
    }

    func getPoints() -> [Point] {
        return self.points
    }
}

func main() {
    let initial_points = [Point(x: 1, y: 2, z: 3), Point(x: 4, y: 5, z: 6), Point(x: 7, y: 8, z: 9)]
    let translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
    let rotations = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    let scales = [[2, 2, 2], [3, 3, 3], [4, 4, 4]]
    let sequence = Sequence(points: initial_points)
    sequence.applyTransformations(translations: translations, rotations: rotations, scales: scales)
    let transformed_points = sequence.getPoints()
    for point in transformed_points {
        print(point)
    }
}

main()