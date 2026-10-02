class Vector3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other: Vector3D): Vector3D {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other: Vector3D): Vector3D {
        return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(scalar: number): Vector3D {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    magnitude(): number {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }
}

class Transformation {
    rotation_matrix: number[][];
    translation_vector: Vector3D;

    constructor(rotation_matrix: number[][], translation_vector: Vector3D) {
        this.rotation_matrix = rotation_matrix;
        this.translation_vector = translation_vector;
    }

    apply(vector: Vector3D): Vector3D {
        const x = vector.x * this.rotation_matrix[0][0] + vector.y * this.rotation_matrix[0][1] + vector.z * this.rotation_matrix[0][2];
        const y = vector.x * this.rotation_matrix[1][0] + vector.y * this.rotation_matrix[1][1] + vector.z * this.rotation_matrix[1][2];
        const z = vector.x * this.rotation_matrix[2][0] + vector.y * this.rotation_matrix[2][1] + vector.z * this.rotation_matrix[2][2];
        const translated_vector = new Vector3D(x, y, z).add(this.translation_vector);
        return translated_vector;
    }
}

function generate_sequence(start: Vector3D, transformation: Transformation, steps: number): Vector3D[] {
    const sequence: Vector3D[] = [];
    let current_vector = start;
    for (let i = 0; i < steps; i++) {
        sequence.push(current_vector);
        current_vector = transformation.apply(current_vector);
    }
    return sequence;
}

function main() {
    const start_vector = new Vector3D(1, 0, 0);
    const rotation_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]];
    const translation_vector = new Vector3D(1, 1, 1);
    const transformation = new Transformation(rotation_matrix, translation_vector);
    const sequence = generate_sequence(start_vector, transformation, 10);
    for (const vector of sequence) {
        console.log(`(${vector.x}, ${vector.y}, ${vector.z})`);
    }
}

main();