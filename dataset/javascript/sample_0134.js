function filter_signal(data, kernel) {
    let result = [];
    for (let i = 0; i < data.length - kernel.length + 1; i++) {
        let segment = data.slice(i, i + kernel.length);
        let convolution = segment.reduce((sum, a, index) => sum + a * kernel[index], 0);
        result.push(convolution);
    }
    return result;
}

function apply_boundary_conditions(data, boundary_type='reflect') {
    if (boundary_type === 'reflect') {
        return data.concat(data.slice(data.length - 2, -1).reverse());
    } else if (boundary_type === 'zero') {
        return data.concat(new Array(data.length).fill(0));
    } else if (boundary_type === 'constant') {
        return data.concat(new Array(data.length).fill(data[data.length - 1]));
    } else {
        return data;
    }
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let kernel = [1, 0, -1];
    let extended_data = apply_boundary_conditions(data);
    let filtered_data = filter_signal(extended_data, kernel);
    console.log(filtered_data.slice(0, data.length));
}

main();