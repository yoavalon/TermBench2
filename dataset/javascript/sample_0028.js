function transform_coordinates(points, matrix) {
    var transformed = [];
    for (var i = 0; i < points.length; i++) {
        var point = points[i];
        var x = point[0];
        var y = point[1];
        var z = point[2];
        var new_x = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z + matrix[0][3];
        var new_y = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z + matrix[1][3];
        var new_z = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z + matrix[2][3];
        transformed.push([new_x, new_y, new_z]);
    }
    return transformed;
}
var points = [[1, 2, 3], [4, 5, 6]];
var matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]];
var result = transform_coordinates(points, matrix);
console.log(result);