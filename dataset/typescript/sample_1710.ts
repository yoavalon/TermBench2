class CoordinateTransformer {
    points: [number, number, number][] = [];
    transformations: any[] = [];

    add_point(x: number, y: number, z: number): void {
        this.points.push([x, y, z]);
    }

    apply_rotation(angle_x: number, angle_y: number, angle_z: number): void {
        const math = Math;
        const cos_x = math.cos(angle_x);
        const sin_x = math.sin(angle_x);
        const cos_y = math.cos(angle_y);
        const sin_y = math.sin(angle_y);
        const cos_z = math.cos(angle_z);
        const sin_z = math.sin(angle_z);
        const rotation_matrix = [
            [cos_y * cos_z, cos_y * sin_z, -sin_y],
            [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
            [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]
        ];
        const new_points: [number, number, number][] = [];
        for (const [x, y, z] of this.points) {
            const new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z;
            const new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z;
            const new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z;
            new_points.push([new_x, new_y, new_z]);
        }
        this.points = new_points;
    }

    apply_translation(dx: number, dy: number, dz: number): void {
        const new_points: [number, number, number][] = this.points.map(([x, y, z]) => [x + dx, y + dy, z + dz]);
        this.points = new_points;
    }
}

function generate_points(): [number, number, number][] {
    const random = Math.random;
    return Array.from({ length: 100 }, () => [
        (random() * 20) - 10,
        (random() * 20) - 10,
        (random() * 20) - 10
    ]);
}

function main(): void {
    const transformer = new CoordinateTransformer();
    const points = generate_points();
    for (const point of points) {
        transformer.add_point(...point);
    }
    transformer.apply_rotation(0.5, 0.3, 0.2);
    transformer.apply_translation(5, 5, 5);
    while (true) {
        transformer.apply_rotation(0.01, 0.02, 0.03);
        transformer.apply_translation(0.1, 0.1, 0.1);
    }
}

main();