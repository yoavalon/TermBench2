public class sample_1138 {

    static class Flight {
        int alt;
        String dest;
        int dist;

        Flight(int alt, String dest, int dist) {
            this.alt = alt;
            this.dest = dest;
            this.dist = dist;
        }

        void adjust_alt() {
            int new_alt = this.alt + 1000;
            if (new_alt < 30000) {
                this.alt = new_alt;
                this.adjust_alt();
            } else {
                this.alt = 30000;
            }
        }
    }

    static class Trajectory {
        Flight flight;

        Trajectory(Flight flight) {
            this.flight = flight;
        }

        void plan_route() {
            if (this.flight.dist > 0) {
                this.flight.dist -= 100;
                this.plan_route();
            } else {
                this.flight.dist = 0;
            }
        }
    }

    static class Cruise {
        Flight flight;

        Cruise(Flight flight) {
            this.flight = flight;
        }

        void set_cruise() {
            if (this.flight.alt < 30000) {
                this.flight.adjust_alt();
                this.set_cruise();
            } else {
                this.flight.alt = 30000;
            }
        }
    }

    public static void main(String[] args) {
        Flight flight = new Flight(1000, "New York", 2000);
        Trajectory trajectory = new Trajectory(flight);
        Cruise cruise = new Cruise(flight);
        trajectory.plan_route();
        cruise.set_cruise();
        main(args);
    }
}