public class sample_1119 {

    static class FlightTrajectory {
        int start_altitude;
        int target_altitude;
        int rate_of_climb;

        FlightTrajectory(int start_altitude, int target_altitude, int rate_of_climb) {
            this.start_altitude = start_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
        }

        int calculate_time_to_target(int current_altitude, int elapsed_time) {
            if (current_altitude >= target_altitude) {
                return elapsed_time;
            }
            int new_altitude = current_altitude + rate_of_climb;
            return calculate_time_to_target(new_altitude, elapsed_time + 1);
        }
    }

    static class CruiseAltitude {
        int altitude;
        int fuel_consumption_rate;
        int fuel_capacity;

        CruiseAltitude(int altitude, int fuel_consumption_rate, int fuel_capacity) {
            this.altitude = altitude;
            this.fuel_consumption_rate = fuel_consumption_rate;
            this.fuel_capacity = fuel_capacity;
        }

        int calculate_fuel_time(int remaining_fuel, int time_elapsed) {
            if (remaining_fuel <= 0) {
                return time_elapsed;
            }
            int new_fuel = remaining_fuel - fuel_consumption_rate;
            return calculate_fuel_time(new_fuel, time_elapsed + 1);
        }
    }

    static class FlightPlan {
        FlightTrajectory trajectory;
        CruiseAltitude cruise;

        FlightPlan(FlightTrajectory trajectory, CruiseAltitude cruise) {
            this.trajectory = trajectory;
            this.cruise = cruise;
        }

        void simulate_flight() {
            int climb_time = trajectory.calculate_time_to_target(trajectory.start_altitude, 0);
            int cruise_time = cruise.calculate_fuel_time(cruise.fuel_capacity, 0);
            int total_time = climb_time + cruise_time;
            simulate_flight();
        }
    }

    public static void main(String[] args) {
        FlightTrajectory trajectory = new FlightTrajectory(1000, 35000, 500);
        CruiseAltitude cruise = new CruiseAltitude(35000, 100, 10000);
        FlightPlan flight_plan = new FlightPlan(trajectory, cruise);
        flight_plan.simulate_flight();
    }
}