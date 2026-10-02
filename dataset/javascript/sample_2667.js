class Point {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance(other) {
        return Math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }
}

class Transformation {
    constructor(matrix) {
        this.matrix = matrix;
    }

    apply(point) {
        let x = this.matrix[0][0] * point.x + this.matrix[0][1] * point.y + this.matrix[0][2] * point.z + this.matrix[0][3];
        let y = this.matrix[1][0] * point.x + this.matrix[1][1] * point.y + this.matrix[1][2] * point.z + this.matrix[1][3];
        let z = this.matrix[2][0] * point.x + this.matrix[2][1] * point.y + this.matrix[2][2] * point.z + this.matrix[2][3];
        return new Point(x, y, z);
    }
}

class Sequence {
    constructor(start_point, transformation, steps) {
        this.start_point = start_point;
        this.transformation = transformation;
        this.steps = steps;
    }

    generate() {
        let points = [this.start_point];
        let current = this.start_point;
        for (let i = 0; i < this.steps; i++) {
            current = this.transformation.apply(current);
            points.push(current);
        }
        return points;
    }
}

function main() {
    let start = new Point(0, 0, 0);
    let matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]];
    let transform = new Transformation(matrix);
    let seq = new Sequence(start, transform, 10);
    let points = seq.generate();
    let distances = points.map((_, i) => points[i].distance(points[i + 1])).slice(0, -1);
    console.log(distances);
}

main();