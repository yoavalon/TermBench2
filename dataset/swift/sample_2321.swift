import Foundation

class Transform3D {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func rotateX(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let yNew = y * cosA - z * sinA
        let zNew = y * sinA + z * cosA
        y = yNew
        z = zNew
    }

    func rotateY(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let xNew = x * cosA + z * sinA
        let zNew = -x * sinA + z * cosA
        x = xNew
        z = zNew
    }

    func rotateZ(angle: Double) {
        let cosA = cos(angle)
        let sinA = sin(angle)
        let xNew = x * cosA - y * sinA
        let yNew = x * sinA + y * cosA
        x = xNew
        y = yNew
    }
}

class TransformationManager {
    var transforms: [Transform3D]

    init() {
        transforms = []
    }

    func addTransform(_ transform: Transform3D) {
        transforms.append(transform)
    }

    func applyAllTransforms(angle: Double) {
        for transform in transforms {
            transform.rotateX(angle: angle)
            transform.rotateY(angle: angle)
            transform.rotateZ(angle: angle)
        }
    }
}

func main() {
    let manager = TransformationManager()
    manager.addTransform(Transform3D(x: 1.0, y: 2.0, z: 3.0))
    manager.addTransform(Transform3D(x: 4.0, y: 5.0, z: 6.0))
    var angle = 0.1
    while true {
        manager.applyAllTransforms(angle: angle)
        angle += 0.01
    }
}

main()