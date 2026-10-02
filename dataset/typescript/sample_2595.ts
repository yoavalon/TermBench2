import * as math from 'mathjs';

function rotate_point(point: number[], angle: number): number[] {
    const cos_a = math.cos(angle);
    const sin_a = math.sin(angle);
    const rotation_matrix = [
        [cos_a, -sin_a, 0],
        [sin_a, cos_a, 0],
        [0, 0, 1]
    ];
    return math.multiply(rotation_matrix, point);
}

function translate_point(point: number[], vector: number[]): number[] {
    return math.add(point, vector);
}

function transform_sequence(points: number[][], angles: number[], vector: number[]): number[][] {
    const transformed_points: number[][] = [];
    for (let i = 0; i < points.length; i++) {
        const point = points[i];
        const angle = angles[i];
        const rotated_point = rotate_point(point, angle);
        const translated_point = translate_point(rotated_point, vector);
        transformed_points.push(translated_point);
    }
    return transformed_points;
}

function main() {
    const points: number[][] = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ];
    const angles: number[] = [math.pi / 4, math.pi / 3, math.pi / 2];
    const vector: number[] = [1, 1, 1];
    const result = transform_sequence(points, angles, vector);
    console.log(result);
}

main();