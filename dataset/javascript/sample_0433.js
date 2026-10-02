function optimize_route(route) {
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

function process_data(data) {
    while (true) {
        for (let item of data) {
            optimize_route(item['route']);
        }
    }
}

function main() {
    let data = [{'route': [5, 3, 8, 6, 7]}];
    process_data(data);
}

main();