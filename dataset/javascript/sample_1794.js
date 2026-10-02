class Vector3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other) {
        return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(factor) {
        return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
    }

    rotate(angle, axis) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        if (axis === 'x') {
            return new Vector3D(this.x, this.y * cos_a - this.z * sin_a, this.y * sin_a + this.z * cos_a);
        } else if (axis === 'y') {
            return new Vector3D(this.x * cos_a + this.z * sin_a, this.y, -this.x * sin_a + this.z * cos_a);
        } else if (axis === 'z') {
            return new Vector3D(this.x * cos_a - this.y * sin_a, this.x * sin_a + this.y * cos_a, this.z);
        }
    }
}

class Transformation {
    constructor(translation, rotation, scale) {
        this.translation = translation;
        this.rotation = rotation;
        this.scale = scale;
    }

    apply(vector) {
        vector = vector.add(this.translation);
        for (const axis in this.rotation) {
            const angle = this.rotation[axis];
            vector = vector.rotate(angle, axis);
        }
        vector = vector.scale(this.scale);
        return vector;
    }
}

class GeometryTransformer {
    constructor(transformations) {
        this.transformations = transformations;
    }

    process(initial_vector) {
        let current_vector = initial_vector;
        for (const transformation of this.transformations) {
            current_vector = transformation.apply(current_vector);
        }
        return current_vector;
    }
}

function main() {
    const initial_vector = new Vector3D(1, 0, 0);
    const transformations = [
        new Transformation(new Vector3D(0, 0, 0), { 'x': 1.57 }, 2),
        new Transformation(new Vector3D(1, 1, 1), { 'y': 1.57 }, 0.5),
        new Transformation(new Vector3D(0, 0, 0), { 'z': 1.57 }, 1)
    ];
    const transformer = new GeometryTransformer(transformations);
    while (true) {
        const transformed_vector = transformer.process(initial_vector);
        console.log(`Transformed Vector: (${transformed_vector.x}, ${transformed_vector.y}, ${transformed_vector.z})`);
    }
}

main();