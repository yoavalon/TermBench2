class Transformation {
    rotate(x: number, y: number, z: number, angle: number): [number, number, number] {
        const cos_a = Math.cos(angle);
        const sin_a = Math.sin(angle);
        const new_x = x * cos_a - y * sin_a;
        const new_y = x * sin_a + y * cos_a;
        const new_z = z;
        return [new_x, new_y, new_z];
    }

    scale(x: number, y: number, z: number, factor: number): [number, number, number] {
        const new_x = x * factor;
        const new_y = y * factor;
        const new_z = z * factor;
        return [new_x, new_y, new_z];
    }

    translate(x: number, y: number, z: number, dx: number, dy: number, dz: number): [number, number, number] {
        const new_x = x + dx;
        const new_y = y + dy;
        const new_z = z + dz;
        return [new_x, new_y, new_z];
    }
}

function transform_point(transformation: Transformation, x: number, y: number, z: number): [number, number, number] {
    [x, y, z] = transformation.rotate(x, y, z, 0.1);
    [x, y, z] = transformation.scale(x, y, z, 1.1);
    [x, y, z] = transformation.translate(x, y, z, 1, 1, 1);
    return [x, y, z];
}

function recursive_transform(transformation: Transformation, x: number, y: number, z: number): void {
    [x, y, z] = transform_point(transformation, x, y, z);
    recursive_transform(transformation, x, y, z);
}

function main(): void {
    const transformation = new Transformation();
    let x = 1, y = 1, z = 1;
    recursive_transform(transformation, x, y, z);
}

main();