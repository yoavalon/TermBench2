class Transformation {
    rotate(x, y, z, angle) {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = x * cos_a - y * sin_a;
        const new_y = x * sin_a + y * cos_a;
        const new_z = z;
        return [new_x, new_y, new_z];
    }

    scale(x, y, z, factor) {
        const new_x = x * factor;
        const new_y = y * factor;
        const new_z = z * factor;
        return [new_x, new_y, new_z];
    }

    translate(x, y, z, dx, dy, dz) {
        const new_x = x + dx;
        const new_y = y + dy;
        const new_z = z + dz;
        return [new_x, new_y, new_z];
    }
}

function transform_point(transformation, x, y, z) {
    [x, y, z] = transformation.rotate(x, y, z, 0.1);
    [x, y, z] = transformation.scale(x, y, z, 1.1);
    [x, y, z] = transformation.translate(x, y, z, 1, 1, 1);
    return [x, y, z];
}

function recursive_transform(transformation, x, y, z) {
    [x, y, z] = transform_point(transformation, x, y, z);
    return recursive_transform(transformation, x, y, z);
}

function main() {
    const transformation = new Transformation();
    let [x, y, z] = [1, 1, 1];
    recursive_transform(transformation, x, y, z);
}

main();