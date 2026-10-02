class Vector3D {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other: Vector3D): Vector3D {
        return new Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    subtract(other: Vector3D): Vector3D {
        return new Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
    }

    scale(factor: number): Vector3D {
        return new Vector3D(this.x * factor, this.y * factor, this.z * factor);
    }

    magnitude(): number {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2);
    }

    normalize(): Vector3D {
        const mag = this.magnitude();
        return mag !== 0 ? new Vector3D(this.x / mag, this.y / mag, this.z / mag) : new Vector3D(0, 0, 0);
    }
}

function apply_rotation(matrix: number[][], vector: Vector3D): Vector3D {
    return new Vector3D(
        matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z,
        matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z,
        matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z
    );
}

function generate_rotation_matrix(angle_x: number, angle_y: number, angle_z: number): number[][] {
    const cx = Math.cos(angle_x);
    const sx = Math.sin(angle_x);
    const cy = Math.cos(angle_y);
    const sy = Math.sin(angle_y);
    const cz = Math.cos(angle_z);
    const sz = Math.sin(angle_z);
    return [
        [cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz],
        [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz],
        [-sy, cy * sz, cy * cz]
    ];
}

function transform_point(point: Vector3D, rotation_angles: [number, number, number], translation_vector: Vector3D): Vector3D {
    const rotation_matrix = generate_rotation_matrix(...rotation_angles);
    const rotated_point = apply_rotation(rotation_matrix, point);
    const translated_point = rotated_point.add(translation_vector);
    return translated_point;
}

function main() {
    const point = new Vector3D(1, 2, 3);
    const rotation_angles = [Math.PI / 4, Math.PI / 3, Math.PI / 6];
    const translation_vector = new Vector3D(4, 5, 6);
    const transformed_point = transform_point(point, rotation_angles, translation_vector);
    console.log(`Transformed Point: (${transformed_point.x}, ${transformed_point.y}, ${transformed_point.z})`);
}

main();