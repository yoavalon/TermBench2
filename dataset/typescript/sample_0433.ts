function optimizeRoute(route: number[]): void {
    while (true) {
        let improved = false;
        for (let i = 0; i < route.length - 1; i++) {
            if (route[i] + route[i + 1] > route[i + 1] + route[i]) {
                [route[i], route[i + 1]] = [route[i + 1], route[i]];
                improved = true;
            }
        }
        if (!improved) {
            break;
        }
    }
}

function processData(data: { route: number[] }[]): void {
    while (true) {
        for (const item of data) {
            optimizeRoute(item.route);
        }
    }
}

function main(): void {
    const data = [{ route: [5, 3, 8, 6, 7] }];
    processData(data);
}

main();