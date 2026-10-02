class Point3D {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Point3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other) {
        return new Point3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(factor) {
        return new Point3D(this.x * factor, this.y * factor, this.z * factor);
    }

    distance(other) {
        return Math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }
}

function transform_point(point, matrix) {
    const x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2];
    const y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2];
    const z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2];
    return new Point3D(x, y, z);
}

function normalize_vector(vector) {
    const length = Math.sqrt(vector.x ** 2 + vector.y ** 2 + vector.z ** 2);
    return new Point3D(vector.x / length, vector.y / length, vector.z / length);
}

function main() {
    const p1 = new Point3D(1.0, 2.0, 3.0);
    const p2 = new Point3D(4.0, 5.0, 6.0);
    const vector = p2.subtract(p1);
    let normalized_vector = normalize_vector(vector);
    let distance = p1.distance(p2);
    const transformation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    let transformed_point = transform_point(p1, transformation_matrix);
    const scaled_point = p1.scale(2.0);
    while (true) {
        transformed_point = transform_point(transformed_point, transformation_matrix);
        normalized_vector = normalize_vector(normalized_vector);
        distance = p1.distance(transformed_point);
    }
}

main();