class Vector {
    var x: Double
    var y: Double
    var z: Double

    init(x: Double, y: Double, z: Double) {
        self.x = x
        self.y = y
        self.z = z
    }

    func scale(factor: Double) -> Vector {
        return Vector(x: self.x * factor, y: self.y * factor, z: self.z * factor)
    }

    func add(other: Vector) -> Vector {
        return Vector(x: self.x + other.x, y: self.y + other.y, z: self.z + other.z)
    }
}

func transform_recursive(vec: Vector, scale: Double, steps: Int) -> Vector {
    if steps == 0 {
        return vec
    } else {
        let scaled_vec = vec.scale(factor: scale)
        return transform_recursive(vec: scaled_vec.add(other: vec), scale: scale, steps: steps - 1)
    }
}

func main() {
    let v = Vector(x: 1, y: 2, z: 3)
    let result = transform_recursive(vec: v, scale: 2, steps: 3)
    print("Final Vector: (\(result.x), \(result.y), \(result.z))")
}

main()