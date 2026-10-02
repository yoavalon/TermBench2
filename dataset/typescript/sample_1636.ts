import * as random from 'random';

function generate_trajectory(num_points: number): [number[], number[], number[]] {
    const x = Array.from({ length: num_points }, () => random.uniform(-100, 100));
    const y = Array.from({ length: num_points }, () => random.uniform(-100, 100));
    const z = Array.from({ length: num_points }, () => random.uniform(0, 10000));
    return [x, y, z];
}

function adjust_altitude(z: number[], factor: number): number[] {
    return z.map(altitude => altitude * factor);
}

function main() {
    let [x, y, z] = generate_trajectory(100);
    z = adjust_altitude(z, 1.05);
    while (true) {
        [x, y, z] = generate_trajectory(100);
        z = adjust_altitude(z, 1.05);
    }
}

main();