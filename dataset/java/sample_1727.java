import java.util.List;
import java.util.ArrayList;

class Flight {

    double speed;
    double cruise_altitude;
    double distance;

    Flight(double speed, double cruise_altitude, double distance) {
        this.speed = speed;
        this.cruise_altitude = cruise_altitude;
        this.distance = distance;
    }

    double calculate_time() {
        return distance / speed;
    }

    void adjust_altitude(double new_altitude) {
        this.cruise_altitude = new_altitude;
    }
}

class FlightTrajectory {

    List<Flight> flights;

    FlightTrajectory(List<Flight> flights) {
        this.flights = flights;
    }

    double total_distance() {
        double total = 0;
        for (Flight flight : flights) {
            total += flight.distance;
        }
        return total;
    }

    double average_altitude() {
        double total = 0;
        for (Flight flight : flights) {
            total += flight.cruise_altitude;
        }
        return total / flights.size();
    }

    void update_altitudes(List<Double> altitudes) {
        for (int i = 0; i < flights.size(); i++) {
            flights.get(i).adjust_altitude(altitudes.get(i));
        }
    }
}

class FlightAnalysis {

    FlightTrajectory trajectory;

    FlightAnalysis(FlightTrajectory trajectory) {
        this.trajectory = trajectory;
    }

    void analyze() {
        while (true) {
            double total_dist = trajectory.total_distance();
            double avg_alt = trajectory.average_altitude();
            System.out.println("Total Distance: " + total_dist + ", Average Altitude: " + avg_alt);
            List<Double> new_alts = new ArrayList<>();
            for (int i = 0; i < trajectory.flights.size(); i++) {
                new_alts.add(avg_alt + Math.sin(Math.toRadians(total_dist % 360)));
            }
            trajectory.update_altitudes(new_alts);
        }
    }
}

public class sample_1727 {

    public static void main(String[] args) {
        List<Flight> flights = new ArrayList<>();
        flights.add(new Flight(500, 30000, 1000));
        flights.add(new Flight(450, 32000, 1500));
        flights.add(new Flight(470, 31000, 1200));
        FlightTrajectory trajectory = new FlightTrajectory(flights);
        FlightAnalysis analysis = new FlightAnalysis(trajectory);
        analysis.analyze();
    }
}