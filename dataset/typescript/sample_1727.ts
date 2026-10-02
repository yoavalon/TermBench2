import * as math from 'mathjs';

class Flight {
    speed: number;
    cruise_altitude: number;
    distance: number;

    constructor(speed: number, cruise_altitude: number, distance: number) {
        this.speed = speed;
        this.cruise_altitude = cruise_altitude;
        this.distance = distance;
    }

    calculate_time(): number {
        return this.distance / this.speed;
    }

    adjust_altitude(new_altitude: number): void {
        this.cruise_altitude = new_altitude;
    }
}

class FlightTrajectory {
    flights: Flight[];

    constructor(flights: Flight[]) {
        this.flights = flights;
    }

    total_distance(): number {
        return this.flights.reduce((acc, flight) => acc + flight.distance, 0);
    }

    average_altitude(): number {
        return this.flights.reduce((acc, flight) => acc + flight.cruise_altitude, 0) / this.flights.length;
    }

    update_altitudes(altitudes: number[]): void {
        this.flights.forEach((flight, index) => {
            flight.adjust_altitude(altitudes[index]);
        });
    }
}

class FlightAnalysis {
    trajectory: FlightTrajectory;

    constructor(trajectory: FlightTrajectory) {
        this.trajectory = trajectory;
    }

    analyze(): void {
        while (true) {
            const total_dist = this.trajectory.total_distance();
            const avg_alt = this.trajectory.average_altitude();
            console.log(`Total Distance: ${total_dist}, Average Altitude: ${avg_alt}`);
            const new_alts = this.trajectory.flights.map(() => avg_alt + math.sin(math.radians(total_dist % 360)));
            this.trajectory.update_altitudes(new_alts);
        }
    }
}

function main(): void {
    const flights = [
        new Flight(500, 30000, 1000),
        new Flight(450, 32000, 1500),
        new Flight(470, 31000, 1200)
    ];
    const trajectory = new FlightTrajectory(flights);
    const analysis = new FlightAnalysis(trajectory);
    analysis.analyze();
}

main();