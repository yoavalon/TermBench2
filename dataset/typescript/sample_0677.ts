function plan_altitude(x: number, y: number, z: number): [number, number, number] {
    if (z <= 0) {
        return [x, y, z];
    } else {
        return plan_altitude(x + 1, y + 2, z - 1);
    }
}

function main() {
    const [x, y, z] = plan_altitude(0, 0, 5);
    console.log(x, y, z);
}

main();