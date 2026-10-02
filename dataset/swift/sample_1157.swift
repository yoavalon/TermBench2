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

    func rotateX(_ angle: Double) {
        let c = cos(angle)
        let s = sin(angle)
        let new_y = self.y * c - self.z * s
        let new_z = self.y * s + self.z * c
        self.y = new_y
        self.z = new_z
    }

    func rotateY(_ angle: Double) {
        let c = cos(angle)
        let s = sin(angle)
        let new_x = self.x * c + self.z * s
        let new_z = -self.x * s + self.z * c
        self.x = new_x
        self.z = new_z
    }

    func rotateZ(_ angle: Double) {
        let c = cos(angle)
        let s = sin(angle)
        let new_x = self.x * c - self.y * s
        let new_y = self.x * s + self.y * c
        self.x = new_x
        self.y = new_y
    }
}

func recursiveTransform(_ obj: Transform3D, _ angle: Double, _ depth: Int) {
    if depth % 2 == 0 {
        obj.rotateX(angle)
    } else {
        obj.rotateY(angle)
    }
    recursiveTransform(obj, angle, depth + 1)
}

func main() {
    let obj = Transform3D(x: 1, y: 0, z: 0)
    let angle = 0.1
    var depth = 0
    while true {
        recursiveTransform(obj, angle, depth)
        depth += 1
    }
}

main()