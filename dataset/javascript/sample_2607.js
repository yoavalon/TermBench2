function calculateAltitudeProfile(distance, speed, rateOfClimb, cruiseAltitude, descentRate) {
    let times = [];
    let altitudes = [];
    let currentTime = 0;
    let currentAltitude = 0;
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

function analyzeFlightProfile(times, altitudes) {
    let maxAltitude = Math.max(...altitudes);
    let cruiseStartTime = times[altitudes.indexOf(cruiseAltitude)];
    let descentStartTime = times[times.length - 1];
    return [maxAltitude, cruiseStartTime, descentStartTime];
}

function main() {
    let distance = 1000;
    let speed = 800;
    let rateOfClimb = 100;
    let cruiseAltitude = 10000;
    let descentRate = 50;
    let [times, altitudes] = calculateAltitudeProfile(distance, speed, rateOfClimb, cruiseAltitude, descentRate);
    let [maxAltitude, cruiseStartTime, descentStartTime] = analyzeFlightProfile(times, altitudes);
    console.log(`Maximum Altitude: ${maxAltitude} meters`);
    console.log(`Cruise Start Time: ${cruiseStartTime} seconds`);
    console.log(`Descent Start Time: ${descentStartTime} seconds`);
}

main();