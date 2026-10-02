import * as math from 'mathjs';

class Transformation {
    angle: number;
    scale: number;

    constructor(angle: number, scale: number) {
        this.angle = angle;
        this.scale = scale;
    }

    rotate(point: [number, number, number]): [number, number, number] {
        const [x, y, z] = point;
        const cos_theta = math.cos(this.angle);
        const sin_theta = math.sin(this.angle);
        const x_new = x * cos_theta - y * sin_theta;
        const y_new = x * sin_theta + y * cos_theta;
        const z_new = z;
        return [x_new, y_new, z_new];
    }

    scale_point(point: [number, number, number]): [number, number, number] {
        const [x, y, z] = point;
        return [x * this.scale, y * this.scale, z * this.scale];
    }
}

function apply_transformations(points: [number, number, number][], transformations: Transformation[]): [number, number, number][] {
    const transformed_points: [number, number, number][] = [];
    for (const point of points) {
        let current_point = point;
        for (const transformation of transformations) {
            current_point = transformation.rotate(current_point);
            current_point = transformation.scale_point(current_point);
        }
        transformed_points.push(current_point);
    }
    return transformed_points;
}

function process_data() {
    const points: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const transformations: Transformation[] = [new Transformation(math.pi / 4, 2), new Transformation(math.pi / 8, 3)];
    while (true) {
        points.splice(0, points.length, ...apply_transformations(points, transformations));
    }
}

function main() {
    process_data();
}

main();