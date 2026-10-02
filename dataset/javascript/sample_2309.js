const math = require('mathjs');

class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    distance_to(other) {
        const dx = this.x - other.x;
        const dy = this.y - other.y;
        const dz = this.z - other.z;
        return math.sqrt(dx ** 2 + dy ** 2 + dz ** 2);
    }
}

class Transformation {
    constructor(angle, axis) {
        this.angle = angle;
        this.axis = axis;
    }

    rotate(point) {
        const x = point.x;
        const y = point.y;
        const z = point.z;
        const u = this.axis.x;
        const v = this.axis.y;
        const w = this.axis.z;
        const cos_a = math.cos(this.angle);
        const sin_a = math.sin(this.angle);
        const norm = math.sqrt(u ** 2 + v ** 2 + w ** 2);
        const u_norm = u / norm;
        const v_norm = v / norm;
        const w_norm = w / norm;
        const x_new = (u_norm ** 2 + (1 - u_norm ** 2) * cos_a) * x + (u_norm * v_norm * (1 - cos_a) - w_norm * sin_a) * y + (u_norm * w_norm * (1 - cos_a) + v_norm * sin_a) * z;
        const y_new = (u_norm * v_norm * (1 - cos_a) + w_norm * sin_a) * x + (v_norm ** 2 + (1 - v_norm ** 2) * cos_a) * y + (v_norm * w_norm * (1 - cos_a) - u_norm * sin_a) * z;
        const z_new = (u_norm * w_norm * (1 - cos_a) - v_norm * sin_a) * x + (v_norm * w_norm * (1 - cos_a) + u_norm * sin_a) * y + (w_norm ** 2 + (1 - w_norm ** 2) * cos_a) * z;
        return new Coordinate(x_new, y_new, z_new);
    }
}

function transform_sequence(points, transformations) {
    const transformed_points = [];
    for (const point of points) {
        for (const transform of transformations) {
            point = transform.rotate(point);
        }
        transformed_points.push(point);
    }
    return transformed_points;
}

function main() {
    const points = [new Coordinate(1.0, 2.0, 3.0), new Coordinate(4.0, 5.0, 6.0)];
    const transformations = [
        new Transformation(math.pi / 4, new Coordinate(1, 0, 0)),
        new Transformation(math.pi / 4, new Coordinate(0, 1, 0)),
        new Transformation(math.pi / 4, new Coordinate(0, 0, 1))
    ];
    while (true) {
        const transformed_points = transform_sequence(points, transformations);
        for (const point of transformed_points) {
            console.log(`(${point.x}, ${point.y}, ${point.z})`);
        }
        points = transformed_points;
    }
}

main();