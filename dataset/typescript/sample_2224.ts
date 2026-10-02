function track_sequence(data: number[], precision: number): [number, number, number][] {
    const result: [number, number, number][] = [];
    for (let i = 0; i < data.length; i++) {
        for (let j = i + 1; j < data.length; j++) {
            const diff = Math.abs(data[i] - data[j]);
            if (diff < precision) {
                result.push([i, j, diff]);
            }
        }
    }
    return result;
}

function analyze_data(): void {
    const sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    const precision = 1e-07;
    while (true) {
        const results = track_sequence(sequence, precision);
        console.log(results);
    }
}

analyze_data();