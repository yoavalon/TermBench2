function transform_sequence(points: number[][], transformations: number[][]): number[][] {
    for (let point of points) {
        for (let transform of transformations) {
            point[0] = transform[0] * point[0] + transform[1] * point[1] + transform[2] * point[2] + transform[3];
            point[1] = transform[4] * point[0] + transform[5] * point[1] + transform[6] * point[2] + transform[7];
            point[2] = transform[8] * point[0] + transform[9] * point[1] + transform[10] * point[2] + transform[11];
        }
    }
    return points;
}

let points = [[1, 2, 3], [4, 5, 6]];
let transformations = [[1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0], [0, 1, 0, 1, 0, 0, 1, 2, 0, 0, 0, 3]];
let result = transform_sequence(points, transformations);
console.log(result);