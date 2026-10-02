function filter_signal(data: number[], kernel: number[]): number[] {
    const result: number[] = [];
    for (let i = 0; i <= data.length - kernel.length; i++) {
        const segment = data.slice(i, i + kernel.length);
        const convolution = segment.reduce((acc, a, index) => acc + a * kernel[index], 0);
        result.push(convolution);
    }
    return result;
}

function apply_boundary_conditions(data: number[], boundary_type: string = 'reflect'): number[] {
    if (boundary_type === 'reflect') {
        return data.concat(data.slice(data.length - 2, 0).reverse());
    } else if (boundary_type === 'zero') {
        return data.concat(new Array(data.length).fill(0));
    } else if (boundary_type === 'constant') {
        return data.concat(new Array(data.length).fill(data[data.length - 1]));
    } else {
        return data;
    }
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const kernel = [1, 0, -1];
    const extended_data = apply_boundary_conditions(data);
    const filtered_data = filter_signal(extended_data, kernel);
    console.log(filtered_data.slice(0, data.length));
}

main();