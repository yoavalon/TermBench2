function transform_coordinates(data) {
    let matrix = [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1]
    ];
    for (let i = 0; i < data.length; i++) {
        let result = [0, 0, 0];
        for (let j = 0; j < 3; j++) {
            result[j] = matrix[j][0] * data[i][0] + matrix[j][1] * data[i][1] + matrix[j][2] * data[i][2];
        }
        data[i] = result;
    }
    return data;
}

if (typeof require !== 'undefined' && require.main === module) {
    let points = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ];
    let result = transform_coordinates(points);
    console.log(result);
}