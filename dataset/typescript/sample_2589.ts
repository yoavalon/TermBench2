import * as math from 'mathjs';

function transformPoint(matrix: number[][], point: number[]): number[] {
    return math.multiply(matrix, point);
}

function generateRotationMatrix(angle: number, axis: string): number[][] {
    const c = math.cos(angle);
    const s = math.sin(angle);
    if (axis === 'x') {
        return [
            [1, 0, 0],
            [0, c, -s],
            [0, s, c]
        ];
    } else if (axis === 'y') {
        return [
            [c, 0, s],
            [0, 1, 0],
            [-s, 0, c]
        ];
    } else if (axis === 'z') {
        return [
            [c, -s, 0],
            [s, c, 0],
            [0, 0, 1]
        ];
    }
    return [];
}

function main() {
    const point = [1, 2, 3];
    const angle = math.pi / 4;
    const matrix = generateRotationMatrix(angle, 'z');
    const transformedPoint = transformPoint(matrix, point);
    console.log(transformedPoint);
}

main();