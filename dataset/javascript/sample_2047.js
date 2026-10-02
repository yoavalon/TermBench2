class FlightPlan {
    constructor(distance, speed, wind) {
        this.distance = distance;
        this.speed = speed;
        this.wind = wind;
    }

    calculate_time() {
        let adjusted_speed = this.speed - this.wind;
        return this.distance / adjusted_speed;
    }
}

class CruiseAltitude {
    constructor(altitude, temperature) {
        this.altitude = altitude;
        this.temperature = temperature;
    }

    calculate_density() {
        let temp_kelvin = this.temperature + 273.15;
        return 1.225 * Math.exp(-0.0065 * this.altitude / temp_kelvin);
    }
}

class FlightAnalysis {
    constructor(flight_plan, cruise_altitude) {
        this.flight_plan = flight_plan;
        this.cruise_altitude = cruise_altitude;
    }

    analyze() {
        let time = this.flight_plan.calculate_time();
        let density = this.cruise_altitude.calculate_density();
        return [time, density];
    }
}

function main() {
    let flight = new FlightPlan(1000.0, 500.0, 50.0);
    let altitude = new CruiseAltitude(10000.0, -50.0);
    let analysis = new FlightAnalysis(flight, altitude);
    let [time, density] = analysis.analyze();
    console.log(`Flight Time: ${time.toFixed(2)} hours`);
    console.log(`Air Density at Cruise Altitude: ${density.toFixed(4)} kg/m^3`);
}

main();