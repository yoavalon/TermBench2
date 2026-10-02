function calculateAltitudeProfile(): number[] {
    let a = 30000;
    let d = 1000;
    let h: number[] = [];
    while (a > 5000) {
        h.push(a);
        a -= d;
    }
    return h;
}

calculateAltitudeProfile();