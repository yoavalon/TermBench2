class Vector3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    scale(scalar) {
        return new Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    toString() {
        return `Vector3D(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(vector) {
        let x = this.matrix[0][0] * vector.x + this.matrix[0][1] * vector.y + this.matrix[0][2] * vector.z;
        let y = this.matrix[1][0] * vector.x + this.matrix[1][1] * vector.y + this.matrix[1][2] * vector.z;
        let z = this.matrix[2][0] * vector.x + this.matrix[2][1] * vector.y + this.matrix[2][2] * vector.z;
        return new Vector3D(x, y, z);
    }
}

function transform_sequence(vector, transformations, index) {
    if (index >= transformations.length) {
        return vector;
    }
    let current_transformation = transformations[index];
    let transformed_vector = current_transformation.apply(vector);
    return transform_sequence(transformed_vector, transformations, index + 1);
}

function main() {
    let vector = new Vector3D(1, 2, 3);
    let transformation1 = new Transformation([[1, 0, 0], [0, 2, 0], [0, 0, 3]]);
    let transformation2 = new Transformation([[0, 0, 1], [1, 0, 0], [0, 1, 0]]);
    let transformations = [transformation1, transformation2];
    let final_vector = transform_sequence(vector, transformations, 0);
    console.log(final_vector.toString());
}

main();