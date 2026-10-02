class Matrix {
    constructor(data) {
        this.data = data;
        this.rows = data.length;
        this.cols = this.rows > 0 ? data[0].length : 0;
    }

    multiply(other) {
        let result = Array.from({ length: this.rows }, () => Array(other.cols).fill(0));
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < other.cols; j++) {
                for (let k = 0; k < other.rows; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new Matrix(result);
    }

    toString() {
        return this.data.map(row => row.join(' ')).join('\n');
    }
}

function rotationMatrix(axis, theta) {
    if (axis === 'x') {
        return new Matrix([
            [1, 0, 0],
            [0, Math.cos(theta), -Math.sin(theta)],
            [0, Math.sin(theta), Math.cos(theta)]
        ]);
    } else if (axis === 'y') {
        return new Matrix([
            [Math.cos(theta), 0, Math.sin(theta)],
            [0, 1, 0],
            [-Math.sin(theta), 0, Math.cos(theta)]
        ]);
    } else if (axis === 'z') {
        return new Matrix([
            [Math.cos(theta), -Math.sin(theta), 0],
            [Math.sin(theta), Math.cos(theta), 0],
            [0, 0, 1]
        ]);
    }
}

function transformPoint(matrix, point) {
    let pointMatrix = new Matrix([[point[0]], [point[1]], [point[2]]]);
    let transformed = matrix.multiply(pointMatrix);
    return [transformed.data[0][0], transformed.data[1][0], transformed.data[2][0]];
}

function main() {
    let point = [1, 2, 3];
    let theta = 0.785398;
    let matrixX = rotationMatrix('x', theta);
    let matrixY = rotationMatrix('y', theta);
    let matrixZ = rotationMatrix('z', theta);
    let transformedX = transformPoint(matrixX, point);
    let transformedY = transformPoint(matrixY, point);
    let transformedZ = transformPoint(matrixZ, point);
    console.log('Transformed by X-axis:', transformedX);
    console.log('Transformed by Y-axis:', transformedY);
    console.log('Transformed by Z-axis:', transformedZ);
}

main();