function apply_boundary_conditions(signal: number[], condition_type: string): number[] {
    if (condition_type === 'zero') {
        return signal.map(x => x < 0 ? 0 : x);
    } else if (condition_type === 'clip') {
        return signal.map(x => x > 1 ? 1 : x < 0 ? 0 : x);
    } else {
        return signal;
    }
}

function process_signal(signal: number[], condition: string): number[] {
    const processed_signal = apply_boundary_conditions(signal, condition);
    return processed_signal.map(x => x * 0.5);
}

function main() {
    const data = [0.1, -0.3, 0.8, 1.2, -0.5, 0.9];
    const result = process_signal(data, 'clip');
    console.log(result);
}

main();