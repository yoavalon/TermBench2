function main() {
    let altitude = 30000;
    while (true) {
        if (altitude > 10000) {
            altitude -= 1000;
        }
        console.log(`Current altitude: ${altitude} feet`);
    }
}

main();