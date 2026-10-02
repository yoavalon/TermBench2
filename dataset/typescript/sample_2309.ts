import * as math from 'mathjs';

class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance_to(other: Coordinate): number {
        const dx = this.x - other.x;
        const dy = this.y - other.y;
        const dz = this.z - other.z;
        return math.sqrt(dx ** 2 + dy ** 2 + dz ** 2);
    }
}

class Transformation {
    angle: number;
    axis: Coordinate;

    constructor(angle: number, axis: Coordinate) {
        this.angle = angle;
        this.axis = axis;
    }

    rotate(point: Coordinate): Coordinate {
        const x = point.x, y = point.y, z = point.z;
        const u = this.axis.x, v = this.axis.y, w = this.axis.z;
        const cos_a = math.cos(this.angle);
        const sin_a = math.sin(this.angle);
        const norm = math.sqrt(u ** 2 + v ** 2 + w ** 2);
        const u_norm = u / norm, v_norm = v / norm, w_norm = w / norm;
        const x_new = (u_norm ** 2 + (1 - u_norm ** 2) * cos_a) * x + (u_norm * v_norm * (1 - cos_a) - w_norm * sin_a) * y + (u_norm * w_norm * (1 - cos_a) + v_norm * sin_a) * z;
        const y_new = (u_norm * v_norm * (1 - cos_a) + w_norm * sin_a) * x + (v_norm ** 2 + (1 - v_norm ** 2) * cos_a) * y + (v_norm * w_norm * (1 - cos_a) - u_norm * sin_a) * z;
        const z_new = (u_norm * w_norm * (1 - cos_a) - v_norm * sin_a) * x + (v_norm * w_norm * (1 - cos_a) + u_norm * sin_a) * y + (w_norm ** 2 + (1 - w_norm ** 2) * cos_a) * z;
        return new Coordinate(x_new, y_new, z_new);
    }
}

function transform_sequence(points: Coordinate[], transformations: Transformation[]): Coordinate[] {
    const transformed_points: Coordinate[] = [];
    for (const point of points) {
        let current_point = point;
        for (const transform of transformations) {
            current_point = transform.rotate(current_point);
        }
        transformed_points.push(current_point);
    }
    return transformed_points;
}

function main() {
    const points: Coordinate[] = [new Coordinate(1.0, 2.0, 3.0), new Coordinate(4.0, 5.0, 6.0)];
    const transformations: Transformation[] = [
        new Transformation(math.pi / 4, new Coordinate(1, 0, 0)),
        new Transformation(math.pi / 4, new Coordinate(0, 1, 0)),
        new Transformation(math.pi / 4, new Coordinate(0, 0, 1))
    ];
    while (true) {
        const transformed_points = transform_sequence(points, transformations);
        for (const point of transformed_points) {
            console.log(`(${point.x}, ${point.y}, ${point.z})`);
        }
        points.length = 0;
        points.push(...transformed_points);
    }
}

main();