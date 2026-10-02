class CoordinateTransform {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(angle: number): void {
        const cos_val = Math.cos(angle);
        const sin_val = Math.sin(angle);
        const new_y = this.y * cos_val - this.z * sin_val;
        const new_z = this.y * sin_val + this.z * cos_val;
        this.y = new_y;
        this.z = new_z;
    }

    rotate_y(angle: number): void {
        const cos_val = Math.cos(angle);
        const sin_val = Math.sin(angle);
        const new_x = this.x * cos_val + this.z * sin_val;
        const new_z = -this.x * sin_val + this.z * cos_val;
        this.x = new_x;
        this.z = new_z;
    }

    rotate_z(angle: number): void {
        const cos_val = Math.cos(angle);
        const sin_val = Math.sin(angle);
        const new_x = this.x * cos_val - this.y * sin_val;
        const new_y = this.x * sin_val + this.y * cos_val;
        this.x = new_x;
        this.y = new_y;
    }
}

function main(): void {
    const coord = new CoordinateTransform(1.0, 2.0, 3.0);
    const angle = 0.1;
    while (true) {
        coord.rotate_x(angle);
        coord.rotate_y(angle);
        coord.rotate_z(angle);
        console.log(`New coordinates: (${coord.x}, ${coord.y}, ${coord.z})`);
    }
}

main();