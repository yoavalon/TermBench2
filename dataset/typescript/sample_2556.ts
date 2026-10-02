function transform_point(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    return [x + a, y + b, z + c];
}

function apply_sequence(points: [number, number, number][], seq: [number, number, number][]): [number, number, number][] {
    const result: [number, number, number][] = [];
    for (const point of points) {
        let transformed = point;
        for (const transform of seq) {
            transformed = transform_point(...transformed, ...transform);
        }
        result.push(transformed);
    }
    return result;
}

function main() {
    const points: [number, number, number][] = [[1, 2, 3], [4, 5, 6]];
    const sequence: [number, number, number][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const transformed_points = apply_sequence(points, sequence);
    console.log(transformed_points);
}

main();