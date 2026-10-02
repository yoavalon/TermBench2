function transform_coordinates(coords, rotation_matrix) {
    var x = coords[0];
    var y = coords[1];
    var z = coords[2];
    var a = rotation_matrix[0];
    var b = rotation_matrix[1];
    var c = rotation_matrix[2];
    var d = rotation_matrix[3];
    var e = rotation_matrix[4];
    var f = rotation_matrix[5];
    var g = rotation_matrix[6];
    var h = rotation_matrix[7];
    var i = rotation_matrix[8];
    return [a * x + b * y + c * z, d * x + e * y + f * z, g * x + h * y + i * z];
}

function main() {
    var coords = [1, 2, 3];
    var rotation_matrix = [1, 0, 0, 0, 1, 0, 0, 0, 1];
    var new_coords = transform_coordinates(coords, rotation_matrix);
    console.log(new_coords);
}

main();