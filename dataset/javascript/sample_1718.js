class Transformation {
    constructor(a, b, c, d, e, f, g, h, i) {
        this.matrix = [[a, b, c], [d, e, f], [g, h, i]];
    }

    apply(point) {
        const [x, y, z] = point;
        const new_x = this.matrix[0][0] * x + this.matrix[0][1] * y + this.matrix[0][2] * z;
        const new_y = this.matrix[1][0] * x + this.matrix[1][1] * y + this.matrix[1][2] * z;
        const new_z = this.matrix[2][0] * x + this.matrix[2][1] * y + this.matrix[2][2] * z;
        return [new_x, new_y, new_z];
    }
}

function rotateX(matrix, angle) {
    const cosAngle = Math.cos(angle);
    const sinAngle = Math.sin(angle);
    const transformation = new Transformation(1, 0, 0, 0, cosAngle, -sinAngle, 0, sinAngle, cosAngle);
    return transformation.apply(matrix);
}

function rotateY(matrix, angle) {
    const cosAngle = Math.cos(angle);
    const sinAngle = Math.sin(angle);
    const transformation = new Transformation(cosAngle, 0, sinAngle, 0, 1, 0, -sinAngle, 0, cosAngle);
    return transformation.apply(matrix);
}

function rotateZ(matrix, angle) {
    const cosAngle = Math.cos(angle);
    const sinAngle = Math.sin(angle);
    const transformation = new Transformation(cosAngle, -sinAngle, 0, sinAngle, cosAngle, 0, 0, 0, 1);
    return transformation.apply(matrix);
}

function main() {
    let point = [1, 1, 1];
    const angle = Math.PI / 4;
    while (true) {
        point = rotateX(point, angle);
        point = rotateY(point, angle);
        point = rotateZ(point, angle);
        console.log(point);
    }
}

main();