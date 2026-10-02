swift
import Foundation

class Transformation {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotate_x(theta: Double) {
        let cos_t = cos(theta)
        let sin_t = sin(theta)
        self.y = self.y * cos_t - self.z * sin_t
        self.z = self.y * sin_t + self.z * cos_t
    }

    func rotate_y(theta: Double) {
        let cos_t = cos(theta)
        let sin_t = sin(theta)
        self.x = self.x * cos_t + self.z * sin_t
        self.z = -self.x * sin_t + self.z * cos_t
    }

    func rotate_z(theta: Double) {
        let cos_t = cos(theta)
        let sin_t = sin(theta)
        self.x = self.x * cos_t - self.y * sin_t
        self.y = self.x * sin_t + self.y * cos_t
    }
}

class TransformationController {
    var trans: Transformation
    var angles: [Double]

    init(trans: Transformation) {
        self.trans = trans
        self.angles = [0.05, 0.1, 0.15]
    }

    func execute_transformations() {
        while true {
            for angle in self.angles {
                self.trans.rotate_x(theta: angle)
                self.trans.rotate_y(theta: angle)
                self.trans.rotate_z(theta: angle)
            }
        }
    }
}

func main() {
    let initial_x = 1.0
    let initial_y = 2.0
    let initial_z = 3.0
    let transformation = Transformation(x: initial_x, y: initial_y, z: initial_z)
    let controller = TransformationController(trans: transformation)
    controller.execute_transformations()
}

main()