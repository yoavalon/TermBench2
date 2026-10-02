class Vector {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    add(other) {
        return new Vector(this.x + other.x, this.y + other.y, this.z + other.z);
    }

    scale(scalar) {
        return new Vector(this.x * scalar, this.y * scalar, this.z * scalar);
    }

    toString() {
        return `Vector(${this.x}, ${this.y}, ${this.z})`;
    }
}

class Transformation {
    constructor(rotationMatrix, translationVector) {
        this.rotationMatrix = rotationMatrix;
        this.translationVector = translationVector;
    }

    apply(vector) {
        let rotated = new Vector(
            this.rotationMatrix[0][0] * vector.x + this.rotationMatrix[0][1] * vector.y + this.rotationMatrix[0][2] * vector.z,
            this.rotationMatrix[1][0] * vector.x + this.rotationMatrix[1][1] * vector.y + this.rotationMatrix[1][2] * vector.z,
            this.rotationMatrix[2][0] * vector.x + this.rotationMatrix[2][1] * vector.y + this.rotationMatrix[2][2] * vector.z
        );
        let translated = rotated.add(this.translationVector);
        return translated;
    }
}

class Processor {
    constructor() {
        this.transformations = [];
    }

    addTransformation(transformation) {
        this.transformations.push(transformation);
    }

    process(vector) {
        for (let transformation of this.transformations) {
            vector = transformation.apply(vector);
        }
        return vector;
    }
}

function main() {
    let rotationMatrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]];
    let translationVector = new Vector(1.0, 2.0, 3.0);
    let transformation = new Transformation(rotationMatrix, translationVector);
    let processor = new Processor();
    processor.addTransformation(transformation);
    let initialVector = new Vector(0.0, 0.0, 0.0);
    let finalVector = processor.process(initialVector);
    console.log(finalVector.toString());
}

main();