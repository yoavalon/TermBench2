class Vector {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other: Vector): Vector {
        return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    scale(scalar: number): Vector {
        return new Vector(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    toString(): string {
        return `Vector(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Transformation {
    rotation_matrix: number[][];
    translation_vector: Vector;

    constructor(rotation_matrix: number[][], translation_vector: Vector) {
        this.rotation_matrix = rotation_matrix;
        this.translation_vector = translation_vector;
    }

    apply(vector: Vector): Vector {
        const rotated = new Vector(
            this.rotation_matrix[0][0] * vector.x + this.rotation_matrix[0][1] * vector.y + this.rotation_matrix[0][2] * vector.z,
            this.rotation_matrix[1][0] * vector.x + this.rotation_matrix[1][1] * vector.y + this.rotation_matrix[1][2] * vector.z,
            this.rotation_matrix[2][0] * vector.x + this.rotation_matrix[2][1] * vector.y + this.rotation_matrix[2][2] * vector.z
        );
        const translated = rotated.add(this.translation_vector);
        return translated;
    }
}

class Processor {
    transformations: Transformation[] = [];

    add_transformation(transformation: Transformation): void {
        this.transformations.push(transformation);
    }

    process(vector: Vector): Vector {
        for (const transformation of this.transformations) {
            vector = transformation.apply(vector);
        }
        return vector;
    }
}

function main() {
    const rotation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    const translation_vector = new Vector(1.0, 2.0, 3.0);
    const transformation = new Transformation(rotation_matrix, translation_vector);
    const processor = new Processor();
    processor.add_transformation(transformation);
    const initial_vector = new Vector(0.0, 0.0, 0.0);
    const final_vector = processor.process(initial_vector);
    console.log(final_vector.toString());
}

main();