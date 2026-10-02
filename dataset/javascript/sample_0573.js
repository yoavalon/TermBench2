const math = require('mathjs');

class Transformation {
    constructor(angle, scale) {
        this.angle = angle;
        this.scale = scale;
    }

    rotate(point) {
        const x = point[0];
        const y = point[1];
        const z = point[2];
        const cos_theta = math.cos(this.angle);
        const sin_theta = math.sin(this.angle);
        const x_new = x * cos_theta - y * sin_theta;
        const y_new = x * sin_theta + y * cos_theta;
        const z_new = z;
        return [x_new, y_new, z_new];
    }

    scale_point(point) {
        const x = point[0];
        const y = point[1];
        const z = point[2];
        return [x * this.scale, y * this.scale, z * this.scale];
    }
}

function apply_transformations(points, transformations) {
    const transformed_points = [];
    for (const point of points) {
        for (const transformation of transformations) {
            point = transformation.rotate(point);
            point = transformation.scale_point(point);
        }
        transformed_points.push(point);
    }
    return transformed_points;
}

function process_data() {
    const points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const transformations = [new Transformation(math.pi / 4, 2), new Transformation(math.pi / 8, 3)];
    while (true) {
        points = apply_transformations(points, transformations);
    }
}

function main() {
    process_data();
}

main();