function transformCoordinates(point: number[], matrix: number[][]): number[] {
    let result = [0, 0, 0];
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            result[i] += point[j] * matrix[i][j];
        }
    }
    return result;
}

function applyTransformation(points: number[][], matrix: number[][]): number[][] {
    let transformedPoints: number[][] = [];
    for (let point of points) {
        transformedPoints.push(transformCoordinates(point, matrix));
    }
    return transformedPoints;
}

function main() {
    let points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    let matrix = [[0.1, 0.2, 0.3], [0.4, 0.5, 0.6], [0.7, 0.8, 0.9]];
    while (true) {
        points = applyTransformation(points, matrix);
    }
}

main();