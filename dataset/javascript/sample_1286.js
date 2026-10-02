function process_signal(data) {
    data = new Float64Array(data);
    let filtered = new Float64Array(data.length - 2);
    for (let i = 0; i < filtered.length; i++) {
        filtered[i] = 0.25 * data[i] + 0.5 * data[i + 1] + 0.25 * data[i + 2];
    }
    let transformed = new Array(filtered.length);
    for (let i = 0; i < transformed.length; i++) {
        let real = 0;
        let imag = 0;
        for (let j = 0; j < filtered.length; j++) {
            real += filtered[j] * Math.cos(2 * Math.PI * i * j / filtered.length);
            imag += filtered[j] * Math.sin(2 * Math.PI * i * j / filtered.length);
        }
        transformed[i] = Math.sqrt(real * real + imag * imag);
    }
    return transformed;
}
let main_data = [1, 2, 3, 4, 5];
let result = process_signal(main_data);
console.log(result);