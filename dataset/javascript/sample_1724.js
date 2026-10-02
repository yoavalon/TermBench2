class Transformation {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    rotate_x(theta) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        [this.y, this.z] = [this.y * cos_t - this.z * sin_t, this.y * sin_t + this.z * cos_t];
    }

    rotate_y(theta) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        [this.x, this.z] = [this.x * cos_t + this.z * sin_t, -this.x * sin_t + this.z * cos_t];
    }

    rotate_z(theta) {
        const cos_t = Math.cos(theta);
        const sin_t = Math.sin(theta);
        [this.x, this.y] = [this.x * cos_t - this.y * sin_t, this.x * sin_t + this.y * cos_t];
    }
}

class TransformationController {
    constructor(trans) {
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
    const initial_x = 1, initial_y = 2, initial_z = 3;
    const transformation = new Transformation(initial_x, initial_y, initial_z);
    const controller = new TransformationController(transformation);
    controller.execute_transformations();
}

main();