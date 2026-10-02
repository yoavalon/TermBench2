function* sequence_generator() {
    let x = 1;
    while (true) {
        yield x;
        x += 1;
    }
}

function flight_planner(seq_gen: Generator<number>) {
    for (let step of seq_gen) {
        if (step % 50 === 0) {
            console.log(`Cruise altitude adjusted at step ${step}`);
        }
        if (step % 100 === 0) {
            console.log(`Trajectory correction initiated at step ${step}`);
        }
    }
}

function main() {
    const gen = sequence_generator();
    flight_planner(gen);
}

main();