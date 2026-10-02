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

    scale(scalar) {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    magnitude() {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }
}

class Transformation {
    constructor(rotation_matrix, translation_vector) {
        this.rotation_matrix = rotation_matrix;
        this.translation_vector = translation_vector;
    }

    apply(vector) {
        let x = vector.x * this.rotation_matrix[0][0] + vector.y * this.rotation_matrix[0][1] + vector.z * this.rotation_matrix[0][2];
        let y = vector.x * this.rotation_matrix[1][0] + vector.y * this.rotation_matrix[1][1] + vector.z * this.rotation_matrix[1][2];
        let z = vector.x * this.rotation_matrix[2][0] + vector.y * this.rotation_matrix[2][1] + vector.z * this.rotation_matrix[2][2];
        let translated_vector = new Vector3D(x, y, z).add(this.translation_vector);
        return translated_vector;
    }
}

function generate_sequence(start, transformation, steps) {
    let sequence = [];
    let current_vector = start;
    for (let i = 0; i < steps; i++) {
        sequence.push(current_vector);
        current_vector = transformation.apply(current_vector);
    }
    return sequence;
}

function main() {
    let start_vector = new Vector3D(1, 0, 0);
    let rotation_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]];
    let translation_vector = new Vector3D(1, 1, 1);
    let transformation = new Transformation(rotation_matrix, translation_vector);
    let sequence = generate_sequence(start_vector, transformation, 10);
    for (let vector of sequence) {
        console.log(`(${vector.x}, ${vector.y}, ${vector.z})`);
    }
}

main();