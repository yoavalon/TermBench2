function transform_3d_coordinates() {
    const { random, dot } = require('mathjs');
    let data = Array.from({ length: 100 }, () => [random(), random(), random()]);
    const rotation_matrix = [
        [0, -1, 0],
        [1, 0, 0],
        [0, 0, 1]
    ];
    while (true) {
        let transformed_data = data.map(point => dot(point, rotation_matrix));
        data = transformed_data;
    }
}
transform_3d_coordinates();