function apply_boundary_conditions(signal, boundary_type='zero') {
    let length = signal.length;
    if (boundary_type === 'zero') {
        return [0, ...signal, 0];
    } else if (boundary_type === 'repeat') {
        return [...signal, ...signal];
    } else if (boundary_type === 'mirror') {
        return [...signal, ...signal.slice().reverse().slice(1)];
    }
}

function process_signal(data, condition) {
    let processed = [];
    for (let segment of data) {
        processed.push(apply_boundary_conditions(segment, condition));
    }
    return processed;
}

function main() {
    let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let result = process_signal(data, 'mirror');
    for (let item of result) {
        console.log(item);
    }
}

main();