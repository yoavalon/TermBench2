function transform_coordinates(points: [number, number, number][], matrix: number[][]): [number, number, number][] {
    const transformed: [number, number, number][] = [];
    for (const point of points) {
        const [x, y, z] = point;
        const x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        const y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        const z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push([x_new, y_new, z_new]);
    }
    return transformed;
}

function apply_transformation(): [number, number, number][] {
    const points: [number, number, number][] = [(1, 2, 3), (4, 5, 6)];
    const matrix: number[][] = [[1, 0, 0, 1], [0, 1, 0, 2], [0, 0, 1, 3]];
    return transform_coordinates(points, matrix);
}

if (require.main === module) {
    const result = apply_transformation();
    console.log(result);
}