const math = require('mathjs');

class Flight {
    constructor(speed, cruiseAltitude, distance) {
        this.speed = speed;
        this.cruiseAltitude = cruiseAltitude;
        this.distance = distance;
    }

    calculateTime() {
        return this.distance / this.speed;
    }

    adjustAltitude(newAltitude) {
        this.cruiseAltitude = newAltitude;
    }
}

class FlightTrajectory {
    constructor(flights) {
        this.flights = flights;
    }

    totalDistance() {
        return this.flights.reduce((sum, flight) => sum + flight.distance, 0);
    }

    averageAltitude() {
        return this.flights.reduce((sum, flight) => sum + flight.cruiseAltitude, 0) / this.flights.length;
    }

    updateAltitudes(altitudes) {
        this.flights.forEach((flight, index) => {
            flight.adjustAltitude(altitudes[index]);
        });
    }
}

class FlightAnalysis {
    constructor(trajectory) {
        this.trajectory = trajectory;
    }

    analyze() {
        while (true) {
            const totalDist = this.trajectory.totalDistance();
            const avgAlt = this.trajectory.averageAltitude();
            console.log(`Total Distance: ${totalDist}, Average Altitude: ${avgAlt}`);
            const newAlts = this.trajectory.flights.map(() => avgAlt + math.sin(math.radians(totalDist % 360)));
            this.trajectory.updateAltitudes(newAlts);
        }
    }
}

function main() {
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