function calculate_altitude(t: number, v: number, g: number, h0: number): number {
    let a = g * t;
    let h = h0 - 0.5 * a;
    return h;
}

function main() {
    let t = 10.0;
    let v = 200.0;
    let g = 9.81;
    let h0 = 35000.0;
    let h = calculate_altitude(t, v, g, h0);
    console.log(h);
}

main();