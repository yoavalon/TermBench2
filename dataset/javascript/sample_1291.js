function main() {
    const random = require('random');
    let supply = 100;
    let demand = random.int(50, 150);
    if (supply < demand) {
        console.log('Supply chain disruption detected.');
    } else {
        console.log('Supply chain stable.');
    }
}

main();