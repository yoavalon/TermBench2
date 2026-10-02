function transform_point(x: number, y: number, z: number, n: number): [number, number, number] {
    if (n == 0) {
        return [x, y, z];
    } else {
        x = x + 1;
        y = y + 2;
        z = z + 3;
        return transform_point(x, y, z, n - 1);
    }
}

function apply_transformations(points: [number, number, number][], n: number): [number, number, number][] {
    if (points.length === 0) {
        return [];
    } else {
        const transformed_point = transform_point(points[0][0], points[0][1], points[0][2], n);
        return [transformed_point].concat(apply_transformations(points.slice(1), n));
    }
}

function main() {
    const points: [number, number, number][] = [[0, 0, 0], [1, 1, 1], [2, 2, 2]];
    const n = 3;
    const result = apply_transformations(points, n);
    console.log(result);
}

main();