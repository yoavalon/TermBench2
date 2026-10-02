function calculateOptimalRoutes(distanceMatrix: number[][], maxRoutes: number): [number, number, number][] {
    const numLocations = distanceMatrix.length;
    const routes: [number, number, number][] = [];
    for (let i = 0; i < numLocations; i++) {
        for (let j = i + 1; j < numLocations; j++) {
            routes.push([i, j, distanceMatrix[i][j]]);
        }
    }
    routes.sort((a, b) => a[2] - b[2]);
    const optimalRoutes: [number, number, number][] = [];
    const selectedPairs = new Set<number>();
    for (const route of routes) {
        if (!selectedPairs.has(route[0]) && !selectedPairs.has(route[1])) {
            optimalRoutes.push(route);
            selectedPairs.add(route[0]);
            selectedPairs.add(route[1]);
            if (optimalRoutes.length === maxRoutes) {
                break;
            }
        }
    }
    return optimalRoutes;
}

function main() {
    const distanceMatrix = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ];
    const maxRoutes = 2;
    const result = calculateOptimalRoutes(distanceMatrix, maxRoutes);
    console.log(result);
}

main();