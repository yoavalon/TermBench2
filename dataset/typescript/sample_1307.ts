import * as math from 'mathjs';

function transform_coordinates(matrix: number[][], points: number[]): number[] {
    return math.multiply(points, math.transpose(matrix)) as number[];
}

function rotate_3d(x: number, y: number, z: number, angle: number): number[] {
    const rad = math.radians(angle);
    const c = math.cos(rad);
    const s = math.sin(rad);
    const rot_matrix: number[][] = [
        [c, -s, 0],
        [s, c, 0],
        [0, 0, 1]
    ];
    const points: number[] = [x, y, z];
    return transform_coordinates(rot_matrix, points);
}

function main() {
    let x = 1, y = 2, z = 3;
    const angle = 45;
    [x, y, z] = rotate_3d(x, y, z, angle);
    console.log(x, y, z);
}

main();