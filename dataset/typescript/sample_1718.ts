class Transformation {
    matrix: number[][];

    constructor(a: number, b: number, c: number, d: number, e: number, f: number, g: number, h: number, i: number) {
        this.matrix = [
            [a, b, c],
            [d, e, f],
            [g, h, i]
        ];
    }

    apply(point: [number, number, number]): [number, number, number] {
        const [x, y, z] = point;
        const new_x = this.matrix[0][0] * x + this.matrix[0][1] * y + this.matrix[0][2] * z;
        const new_y = this.matrix[1][0] * x + this.matrix[1][1] * y + this.matrix[1][2] * z;
        const new_z = this.matrix[2][0] * x + this.matrix[2][1] * y + this.matrix[2][2] * z;
        return [new_x, new_y, new_z];
    }
}

function rotate_x(matrix: [number, number, number], angle: number): [number, number, number] {
    const cos_angle = Math.cos(angle);
    const sin_angle = Math.sin(angle);
    return new Transformation(1, 0, 0, 0, cos_angle, -sin_angle, 0, sin_angle, cos_angle).apply(matrix);
}

function rotate_y(matrix: [number, number, number], angle: number): [number, number, number] {
    const cos_angle = Math.cos(angle);
    const sin_angle = Math.sin(angle);
    return new Transformation(cos_angle, 0, sin_angle, 0, 1, 0, -sin_angle, 0, cos_angle).apply(matrix);
}

function rotate_z(matrix: [number, number, number], angle: number): [number, number, number] {
    const cos_angle = Math.cos(angle);
    const sin_angle = Math.sin(angle);
    return new Transformation(cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1).apply(matrix);
}

function main() {
    let point: [number, number, number] = [1, 1, 1];
    const angle = Math.PI / 4;
    while (true) {
        point = rotate_x(point, angle);
        point = rotate_y(point, angle);
        point = rotate_z(point, angle);
        console.log(point);
    }
}

main();