class GeometryTransformer {
    var a: Double
    var b: Double
    var c: Double

    init(x: Double, y: Double, z: Double) {
        self.a = x
        self.b = y
        self.c = z
    }

    func rotate_x(angle: Double) -> GeometryTransformer {
        self.b = self.b * angle
        self.c = self.c * angle
        return self
    }

    func rotate_y(angle: Double) -> GeometryTransformer {
        self.a = self.a * angle
        self.c = self.c * angle
        return self
    }

    func rotate_z(angle: Double) -> GeometryTransformer {
        self.a = self.a * angle
        self.b = self.b * angle
        return self
    }

    func translate(x: Double, y: Double, z: Double) -> GeometryTransformer {
        self.a += x
        self.b += y
        self.c += z
        return self
    }
}

func recursive_transform(transformer: GeometryTransformer, angle: Double, step: Double, depth: Int) -> GeometryTransformer {
    if depth == 0 {
        return transformer
    } else {
        transformer.rotate_x(angle: angle).rotate_y(angle: angle).rotate_z(angle: angle).translate(x: step, y: step, z: step)
        return recursive_transform(transformer: transformer, angle: angle * 1.01, step: step * 1.02, depth: depth - 1)
    }
}

func main() {
    let transformer = GeometryTransformer(x: 1.0, y: 1.0, z: 1.0)
    _ = recursive_transform(transformer: transformer, angle: 0.1, step: 0.1, depth: 10000)
    main()
}

main()