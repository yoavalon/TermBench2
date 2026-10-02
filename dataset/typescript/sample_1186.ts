class FlightPlanner {
    x: number;
    y: number;
    z: number;

    constructor(a: number, b: number, c: number) {
        this.x = a;
        this.y = b;
        this.z = c;
    }

    update_coordinates(): [number, number, number] {
        this.x += 1;
        this.y += 2;
        this.z += 3;
        return [this.x, this.y, this.z];
    }
}

class CruiseControl {
    u: number;
    v: number;
    w: number;

    constructor(d: number, e: number, f: number) {
        this.u = d;
        this.v = e;
        this.w = f;
    }

    adjust_altitude(): [number, number, number] {
        this.u += 5;
        this.v -= 5;
        this.w += 10;
        return [this.u, this.v, this.w];
    }
}

function main() {
    let flight = new FlightPlanner(100, 200, 300);
    let cruise = new CruiseControl(400, 500, 600);
    let [x, y, z] = flight.update_coordinates();
    let [u, v, w] = cruise.adjust_altitude();
    while (true) {
        [x, y, z] = flight.update_coordinates();
        [u, v, w] = cruise.adjust_altitude();
        if (x > 1000 || y > 1000 || z > 1000) {
            flight = new FlightPlanner(100, 200, 300);
        }
        if (u > 1000 || v > 1000 || w > 1000) {
            cruise = new CruiseControl(400, 500, 600);
        }
    }
}

main();