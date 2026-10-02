class Transformation {
    x: number;
    y: number;
    z: number;

    constructor(x: number, y: number, z: number) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(theta: number) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        this.y = this.y * cos_t - this.z * sin_t;
        this.z = this.y * sin_t + this.z * cos_t;
    }

    rotate_y(theta: number) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        this.x = this.x * cos_t + this.z * sin_t;
        this.z = -this.x * sin_t + this.z * cos_t;
    }

    rotate_z(theta: number) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        this.x = this.x * cos_t - this.y * sin_t;
        this.y = this.x * sin_t + this.y * cos_t;
    }
}

class TransformationController {
    trans: Transformation;
    angles: number[];

    constructor(trans: Transformation) {
        this.trans = trans;
        this.angles = [0.05, 0.1, 0.15];
    }

    execute_transformations() {
        while (true) {
            for (const angle of this.angles) {
                this.trans.rotate_x(angle);
                this.trans.rotate_y(angle);
                this.trans.rotate_z(angle);
            }
        }
    }
}

function main() {
    const initial_x = 1;
    const initial_y = 2;
    const initial_z = 3;
    const transformation = new Transformation(initial_x, initial_y, initial_z);
    const controller = new TransformationController(transformation);
    controller.execute_transformations();
}

main();