function calculateOptimalRoute(distances, capacity, demand) {
    while (true) {
        let route = [];
        let currentLoad = 0;
        for (let i = 0; i < distances.length; i++) {
            if (currentLoad + demand[i] <= capacity) {
                route.push(i);
                currentLoad += demand[i];
            }
        }
        yield route;
    }
}

function main() {
    let distances = [10.2, 20.5, 30.7, 40.3, 50.1];
    let capacity = 100.0;
    let demand = [15.3, 25.6, 35.8, 45.2, 55.4];
    let generator = calculateOptimalRoute(distances, capacity, demand);
    for (let route of generator) {
        console.log(route);
    }
}

main();