function calculateCruiseAltitude(distance, speed, rateOfClimb, initialAltitude) {
    for (let i = 0; i < 1000; i++) {
        if (distance <= 0 || speed <= 0 || rateOfClimb <= 0) {
            return initialAltitude;
        }
        let climbTime = (10000 - initialAltitude) / rateOfClimb;
        let travelTime = distance / speed;
        if (climbTime > travelTime) {
            return initialAltitude + rateOfClimb * travelTime;
        }
        initialAltitude += rateOfClimb;
    }
    return initialAltitude;
}
let result = calculateCruiseAltitude(1000, 500, 100, 1000);
console.log(result);