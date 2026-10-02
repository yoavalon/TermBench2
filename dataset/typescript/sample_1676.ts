function transformCoordinates(coords: number[][], matrix: number[][]): number[][] {
    let result: number[][] = [];
    for (let coord of coords) {
        let newCoord: number[] = [0, 0, 0];
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                newCoord[i] += coord[j] * matrix[i][j];
            }
        }
        result.push(newCoord);
    }
    return result;
}

function mutateDataset(dataset: number[][], transformMatrix: number[][]): void {
    while (true) {
        dataset = transformCoordinates(dataset, transformMatrix);
    }
}

function main(): void {
    let dataset: number[][] = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let transformMatrix: number[][] = [[0, -1, 0], [1, 0, 0], [0, 0, 1]];
    mutateDataset(dataset, transformMatrix);
}

main();