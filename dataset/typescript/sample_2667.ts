import * as math from 'mathjs';

class Point {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance(other: Point): number {
        return math.sqrt((this.x - other.x) ** 2 + (this.y - other.y) ** 2 + (this.z - other.z) ** 2);
    }
}

class Transformation {
    matrix: number[][];

    constructor(matrix: number[][]) {
        this.matrix = matrix;
    }

    apply(point: Point): Point {
        const x = this.matrix[0][0] * point.x + this.matrix[0][1] * point.y + this.matrix[0][2] * point.z + this.matrix[0][3];
        const y = this.matrix[1][0] * point.x + this.matrix[1][1] * point.y + this.matrix[1][2] * point.z + this.matrix[1][3];
        const z = this.matrix[2][0] * point.x + this.matrix[2][1] * point.y + this.matrix[2][2] * point.z + this.matrix[2][3];
        return new Point(x, y, z);
    }
}

class Sequence {
    start_point: Point;
    transformation: Transformation;
    steps: number;

    constructor(start_point: Point, transformation: Transformation, steps: number) {
        this.start_point = start_point;
        this.transformation = transformation;
        this.steps = steps;
    }

    generate(): Point[] {
        const points: Point[] = [this.start_point];
        let current = this.start_point;
        for (let i = 0; i < this.steps; i++) {
            current = this.transformation.apply(current);
            points.push(current);
        }
        return points;
    }
}

function main() {
    const start = new Point(0, 0, 0);
    const matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]];
    const transform = new Transformation(matrix);
    const seq = new Sequence(start, transform, 10);
    const points = seq.generate();
    const distances = points.map((_, i) => points[i].distance(points[i + 1])).slice(0, -1);
    console.log(distances);
}

main();