class FlightPath {
    altitude: number;
    target_altitude: number;
    rate_of_climb: number;

    constructor(start_altitude: number, target_altitude: number, rate_of_climb: number) {
        this.altitude = start_altitude;
        this.target_altitude = target_altitude;
        this.rate_of_climb = rate_of_climb;
    }

    climb() {
        this.altitude += this.rate_of_climb;
        if (this.altitude > this.target_altitude) {
            this.altitude = this.target_altitude;
        }
    }

    get_status() {
        return [this.altitude, this.target_altitude];
    }
}

class CruiseAltitude {
    altitude: number;
    max_speed: number;
    wind_speed: number;

    constructor(altitude: number, max_speed: number, wind_speed: number) {
        this.altitude = altitude;
        this.max_speed = max_speed;
        this.wind_speed = wind_speed;
    }

    adjust_speed() {
        this.max_speed = this.max_speed - this.wind_speed * 0.5;
    }

    get_speed() {
        return this.max_speed;
    }
}

function main() {
    const flight = new FlightPath(1000, 35000, 100);
    const cruise = new CruiseAltitude(35000, 800, 20);
    while (true) {
        flight.climb();
        cruise.adjust_speed();
        const [current_alt, target_alt] = flight.get_status();
        const current_speed = cruise.get_speed();
        if (current_alt === target_alt) {
            console.log(`Reached target altitude: ${current_alt}`);
            console.log(`Cruise speed adjusted to: ${current_speed}`);
        } else {
            console.log(`Current altitude: ${current_alt}, Target altitude: ${target_alt}`);
            console.log(`Current speed: ${current_speed}`);
        }
    }
}

main();