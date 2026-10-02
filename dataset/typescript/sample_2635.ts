import * as math from 'mathjs';

function transform_matrix(rotation: number[][], translation: number[]): number[][] {
    let R = math.matrix(rotation);
    let T = math.matrix(translation);
    let zeroRow = math.zeros(1, 3);
    let oneElement = math.ones(1, 1);
    let block = math.block([[R, T], [zeroRow, oneElement]]);
    return block.valueOf();
}

function apply_transformation(points: number[][], matrix: number[][]): number[][] {
    let homogeneousPoints = points.map(point => [...point, 1]);
    let transformedPoints = math.multiply(homogeneousPoints, math.transpose(matrix));
    return transformedPoints.map(point => point.slice(0, 3));
}

function generate_sequence(n: number, initialPoint: number[], angle: number, axis: number[]): number[][] {
    let sequence: number[][] = [initialPoint];
    let rotationMatrix = math.eye(3);
    for (let _ = 0; _ < n; _++) {
        rotationMatrix = rotate_around_axis(rotationMatrix, angle, axis);
        let transformedPoint = apply_transformation([sequence[sequence.length - 1]], rotationMatrix);
        sequence.push(transformedPoint[0]);
    }
    return sequence;
}

function rotate_around_axis(matrix: number[][], angle: number, axis: number[]): number[][] {
    let cos = math.cos(angle);
    let sin = math.sin(angle);
    let axisNorm = math.norm(axis);
    let ux = axis[0] / axisNorm;
    let uy = axis[1] / axisNorm;
    let uz = axis[2] / axisNorm;
    let rotation = math.matrix([
        [cos + ux ** 2 * (1 - cos), ux * uy * (1 - cos) - uz * sin, ux * uz * (1 - cos) + uy * sin],
        [uy * ux * (1 - cos) + uz * sin, cos + uy ** 2 * (1 - cos), uy * uz * (1 - cos) - ux * sin],
        [uz * ux * (1 - cos) - uy * sin, uz * uy * (1 - cos) + ux * sin, cos + uz ** 2 * (1 - cos)]
    ]);
    return math.multiply(rotation, matrix).valueOf();
}

function main() {
    let initialPoint = [1, 0, 0];
    let angle = math.pi / 4;
    let axis = [0, 0, 1];
    let n = 10;
    let sequence = generate_sequence(n, initialPoint, angle, axis);
    console.log(sequence);
}

main();