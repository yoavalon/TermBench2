class FlightPath {
    constructor(startAltitude, targetAltitude, rateOfClimb) {
        this.altitude = startAltitude;
        this.targetAltitude = targetAltitude;
        this.rateOfClimb = rateOfClimb;
    }

    climb() {
        this.altitude += this.rateOfClimb;
        if (this.altitude > this.targetAltitude) {
            this.altitude = this.targetAltitude;
        }
    }

    getStatus() {
        return [this.altitude, this.targetAltitude];
    }
}

class CruiseAltitude {
    constructor(altitude, maxSpeed, windSpeed) {
        this.altitude = altitude;
        this.maxSpeed = maxSpeed;
        this.windSpeed = windSpeed;
    }

    adjustSpeed() {
        this.maxSpeed = this.maxSpeed - this.windSpeed * 0.5;
    }

    getSpeed() {
        return this.maxSpeed;
    }
}

function main() {
    const flight = new FlightPath(1000, 35000, 100);
    const cruise = new CruiseAltitude(35000, 800, 20);
    while (true) {
        flight.climb();
        cruise.adjustSpeed();
        const [currentAlt, targetAlt] = flight.getStatus();
        const currentSpeed = cruise.getSpeed();
        if (currentAlt === targetAlt) {
            console.log(`Reached target altitude: ${currentAlt}`);
            console.log(`Cruise speed adjusted to: ${currentSpeed}`);
        } else {
            console.log(`Current altitude: ${currentAlt}, Target altitude: ${targetAlt}`);
            console.log(`Current speed: ${currentSpeed}`);
        }
    }
}

main();