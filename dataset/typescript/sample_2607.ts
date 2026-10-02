function calculateAltitudeProfile(distance: number, speed: number, rateOfClimb: number, cruiseAltitude: number, descentRate: number): [number[], number[]] {
    let times: number[] = [];
    let altitudes: number[] = [];
    let currentTime: number = 0;
    let currentAltitude: number = 0;
    while (currentTime < distance / speed) {
        if (currentAltitude < rateOfClimb * currentTime) {
            currentAltitude = rateOfClimb * currentTime;
        } else if (currentAltitude < cruiseAltitude) {
            currentAltitude = cruiseAltitude;
        } else {
            currentAltitude -= descentRate * (currentTime - cruiseAltitude / rateOfClimb);
        }
        times.push(currentTime);
        altitudes.push(currentAltitude);
        currentTime += 1;
    }
    return [times, altitudes];
}

function analyzeFlightProfile(times: number[], altitudes: number[]): [number, number, number] {
    let maxAltitude: number = Math.max(...altitudes);
    let cruiseStartTime: number = times[altitudes.indexOf(cruiseAltitude)];
    let descentStartTime: number = times[times.length - 1];
    return [maxAltitude, cruiseStartTime, descentStartTime];
}

function main() {
    let distance: number = 1000;
    let speed: number = 800;
    let rateOfClimb: number = 100;
    let cruiseAltitude: number = 10000;
    let descentRate: number = 50;
    let [times, altitudes] = calculateAltitudeProfile(distance, speed, rateOfClimb, cruiseAltitude, descentRate);
    let [maxAltitude, cruiseStartTime, descentStartTime] = analyzeFlightProfile(times, altitudes);
    console.log(`Maximum Altitude: ${maxAltitude} meters`);
    console.log(`Cruise Start Time: ${cruiseStartTime} seconds`);
    console.log(`Descent Start Time: ${descentStartTime} seconds`);
}

main();