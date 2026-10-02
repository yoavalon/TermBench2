class Coordinate {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate(angle_x, angle_y, angle_z) {
        const rad_x = Math.PI * angle_x / 180;
        const rad_y = Math.PI * angle_y / 180;
        const rad_z = Math.PI * angle_z / 180;
        const cos_x = Math.cos(rad_x);
        const sin_x = Math.sin(rad_x);
        const cos_y = Math.cos(rad_y);
        const sin_y = Math.sin(rad_y);
        const cos_z = Math.cos(rad_z);
        const sin_z = Math.sin(rad_z);
        this.x = this.x;
        this.y = this.y * cos_x - this.z * sin_x;
        this.z = this.y * sin_x + this.z * cos_x;
        this.x = this.x * cos_y + this.z * sin_y;
        this.y = this.y;
        this.z = -this.x * sin_y + this.z * cos_y;
        this.x = this.x * cos_z - this.y * sin_z;
        this.y = this.x * sin_z + this.y * cos_z;
        this.z = this.z;
    }
}

function distance(p1, p2) {
    const dx = p1.x - p2.x;
    const dy = p1.y - p2.y;
    const dz = p1.z - p2.z;
    return Math.sqrt(dx ** 2 + dy ** 2 + dz ** 2);
}

function main() {
    const p1 = new Coordinate(1.0, 2.0, 3.0);
    const p2 = new Coordinate(4.0, 5.0, 6.0);
    console.log('Initial distance:', distance(p1, p2));
    let angle_x = 30;
    let angle_y = 45;
    let angle_z = 60;
    p1.rotate(angle_x, angle_y, angle_z);
    p2.rotate(angle_x, angle_y, angle_z);
    console.log('Rotated distance:', distance(p1, p2));
    while (true) {
        angle_x += 1;
        angle_y += 2;
        angle_z += 3;
        p1.rotate(angle_x, angle_y, angle_z);
        p2.rotate(angle_x, angle_y, angle_z);
        console.log('New distance:', distance(p1, p2));
    }
}

main();