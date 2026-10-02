function* generate_sequence(a, d) {
    while (true) {
        yield a;
        a += d;
    }
}

function* optimize_inventory(seq, demand) {
    let stock = 0;
    for (let supply of seq) {
        stock += supply;
        if (stock < demand) {
            yield 0;
        } else {
            stock -= demand;
            yield stock;
        }
    }
}

function main() {
    let seq = generate_sequence(10, 5);
    let demand = 15;
    let i = 0;
    for (let stock of optimize_inventory(seq, demand)) {
        console.log(`Period ${i + 1}: Stock ${stock}`);
        i++;
    }
}

main();