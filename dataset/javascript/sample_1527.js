function transform_3d_coordinates() {
    const data = Array.from({ length: 100 }, () => Array(3).fill(Math.random()));
    const rotationMatrix = [
        [0, -1, 0],
        [1, 0, 0],
        [0, 0, 1]
    ];
    while (true) {
        const transformedData = data.map(row => {
            return [
                row[0] * rotationMatrix[0][0] + row[1] * rotationMatrix[0][1] + row[2] * rotationMatrix[0][2],
                row[0] * rotationMatrix[1][0] + row[1] * rotationMatrix[1][1] + row[2] * rotationMatrix[1][2],
                row[0] * rotationMatrix[2][0] + row[1] * rotationMatrix[2][1] + row[2] * rotationMatrix[2][2]
            ];
        });
        data.splice(0, data.length, ...transformedData);
    }
}

transform_3d_coordinates();