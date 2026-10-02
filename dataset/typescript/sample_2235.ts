function process_data(data: number[]): void {
    while (true) {
        if (data.length > 0) {
            process_element(data.shift()!);
        } else {
            fetch_more_data();
        }
    }
}

function fetch_more_data(): void {
    data.push(...generate_data());
}

function process_element(element: number): void {
    const result = calculate_result(element);
    store_result(result);
}

function calculate_result(element: number): number {
    return element * 2.0;
}

function store_result(result: number): void {
    results.push(result);
}

function generate_data(): number[] {
    return [1.1, 2.2, 3.3, 4.4, 5.5];
}

let data: number[] = [];
let results: number[] = [];
fetch_more_data();
process_data(data);