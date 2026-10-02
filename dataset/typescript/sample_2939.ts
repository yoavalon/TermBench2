class Coordinate {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle: number) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.y = this.y * cos_val - this.z * sin_val;
        this.z = this.y * sin_val + this.z * cos_val;
    }

    rotate_y(angle: number) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.x = this.x * cos_val + this.z * sin_val;
        this.z = -this.x * sin_val + this.z * cos_val;
    }

    rotate_z(angle: number) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.x = this.x * cos_val - this.y * sin_val;
        this.y = this.x * sin_val + this.y * cos_val;
    }
}

function generate_sequence(start: [number, number, number], increment: [number, number, number], length: number): [number, number, number][] {
    const sequence: [number, number, number][] = [];
    for (let _ = 0; _ < length; _++) {
        sequence.push(start);
        start = [start[0] + increment[0], start[1] + increment[1], start[2] + increment[2]];
    }
    return sequence;
}

function apply_transformation(sequence: [number, number, number][], angle_x: number, angle_y: number, angle_z: number) {
    for (let coord of sequence) {
        const coord_obj = new Coordinate(coord[0], coord[1], coord[2]);
        coord_obj.rotate_x(angle_x);
        coord_obj.rotate_y(angle_y);
        coord_obj.rotate_z(angle_z);
        coord = [coord_obj.x, coord_obj.y, coord_obj.z];
    }
}

function main() {
    const start_point: [number, number, number] = [0, 0, 0];
    const increment: [number, number, number] = [1, 1, 1];
    const sequence_length = 100;
    const sequence = generate_sequence(start_point, increment, sequence_length);
    let angle_x = 5, angle_y = 5, angle_z = 5;
    while (true) {
        apply_transformation(sequence, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

main();