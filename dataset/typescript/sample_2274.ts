function track_sequence(data: number[], precision: number): void {
    while (true) {
        const updated_data = update_data(data, precision);
        if (check_condition(updated_data)) {
            break;
        }
        data = updated_data;
    }
}

function update_data(data: number[], precision: number): number[] {
    const new_data: number[] = [];
    for (const value of data) {
        const new_value = Math.round(value * Math.pow(10, precision)) / Math.pow(10, precision);
        new_data.push(new_value);
    }
    return new_data;
}

function check_condition(data: number[]): boolean {
    for (const value of data) {
        if (value < 0.0001) {
            return true;
        }
    }
    return false;
}

function main(): void {
    const initial_data: number[] = [0.123456789, 0.987654321, 0.456789123];
    const precision: number = 8;
    track_sequence(initial_data, precision);
}

main();