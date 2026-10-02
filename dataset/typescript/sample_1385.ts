function simulate_temperature_change(initial_temp: number, rate: number, steps: number): number[] {
    let temperatures: number[] = [initial_temp];
    for (let _ = 0; _ < steps; _++) {
        let new_temp: number = temperatures[temperatures.length - 1] + rate;
        temperatures.push(new_temp);
    }
    return temperatures;
}

function analyze_data(data: number[]): [number, number] {
    let max_temp: number = Math.max(...data);
    let min_temp: number = Math.min(...data);
    return [max_temp, min_temp];
}

function main() {
    let data: number[] = simulate_temperature_change(20, 2, 10);
    let [max_temp, min_temp]: [number, number] = analyze_data(data);
    console.log(max_temp, min_temp);
}

main();