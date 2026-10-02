class FlightPlan {
    distance: number;
    speed: number;
    wind: number;

    constructor(distance: number, speed: number, wind: number) {
        this.distance = distance;
        this.speed = speed;
        this.wind = wind;
    }

    calculate_time(): number {
        const adjusted_speed = this.speed - this.wind;
        return this.distance / adjusted_speed;
    }
}

class CruiseAltitude {
    altitude: number;
    temperature: number;

    constructor(altitude: number, temperature: number) {
        this.altitude = altitude;
        this.temperature = temperature;
    }

    calculate_density(): number {
        const temp_kelvin = this.temperature + 273.15;
        return 1.225 * Math.exp(-0.0065 * this.altitude / temp_kelvin);
    }
}

class FlightAnalysis {
    flight_plan: FlightPlan;
    cruise_altitude: CruiseAltitude;

    constructor(flight_plan: FlightPlan, cruise_altitude: CruiseAltitude) {
        this.flight_plan = flight_plan;
        this.cruise_altitude = cruise_altitude;
    }

    analyze(): [number, number] {
        const time = this.flight_plan.calculate_time();
        const density = this.cruise_altitude.calculate_density();
        return [time, density];
    }
}

function main() {
    const flight = new FlightPlan(1000.0, 500.0, 50.0);
    const altitude = new CruiseAltitude(10000.0, -50.0);
    const analysis = new FlightAnalysis(flight, altitude);
    const [time, density] = analysis.analyze();
    console.log(`Flight Time: ${time.toFixed(2)} hours`);
    console.log(`Air Density at Cruise Altitude: ${density.toFixed(4)} kg/m^3`);
}

main();