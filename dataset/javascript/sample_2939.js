class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.y = this.y * cos_val - this.z * sin_val;
        this.z = this.y * sin_val + this.z * cos_val;
    }

    rotate_y(angle) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.x = this.x * cos_val + this.z * sin_val;
        this.z = -this.x * sin_val + this.z * cos_val;
    }

    rotate_z(angle) {
        const angle_rad = angle * Math.PI / 180;
        const cos_val = Math.cos(angle_rad);
        const sin_val = Math.sin(angle_rad);
        this.x = this.x * cos_val - this.y * sin_val;
        this.y = this.x * sin_val + this.y * cos_val;
    }
}

function generate_sequence(start, increment, length) {
    const sequence = [];
    for (let i = 0; i < length; i++) {
        sequence.push(start.slice());
        start = [start[0] + increment[0], start[1] + increment[1], start[2] + increment[2]];
    }
    return sequence;
}

function apply_transformation(sequence, angle_x, angle_y, angle_z) {
    for (let coord of sequence) {
        const coord_obj = new Coordinate(coord[0], coord[1], coord[2]);
        coord_obj.rotate_x(angle_x);
        coord_obj.rotate_y(angle_y);
        coord_obj.rotate_z(angle_z);
        coord[0] = coord_obj.x;
        coord[1] = coord_obj.y;
        coord[2] = coord_obj.z;
    }
}

function main() {
    const start_point = [0, 0, 0];
    const increment = [1, 1, 1];
    const sequence_length = 100;
    const sequence = generate_sequence(start_point, increment, sequence_length);
    let angle_x = 5;
    let angle_y = 5;
    let angle_z = 5;
    while (true) {
        apply_transformation(sequence, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

main();