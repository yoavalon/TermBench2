public class sample_1170 {

    public static class Flight {
        int altitude;
        java.util.ArrayList<Integer> trajectory;

        public Flight(int altitude, java.util.ArrayList<Integer> trajectory) {
            this.altitude = altitude;
            this.trajectory = trajectory;
        }

        public void adjust_altitude() {
            if (this.altitude < 30000) {
                this.altitude += 1000;
                this.trajectory.add(this.altitude);
                this.adjust_altitude();
            } else if (this.altitude < 40000) {
                this.altitude += 500;
                this.trajectory.add(this.altitude);
                this.adjust_altitude();
            } else {
                this.altitude += 100;
                this.trajectory.add(this.altitude);
                this.adjust_altitude();
            }
        }
    }

    public static class CruisePlanner {
        public void plan(Flight flight) {
            if (flight.altitude < 35000) {
                flight.adjust_altitude();
                this.plan(flight);
            } else {
                this.cruise(flight);
            }
        }

        public void cruise(Flight flight) {
            flight.altitude += 50;
            flight.trajectory.add(flight.altitude);
            this.cruise(flight);
        }
    }

    public static void main(String[] args) {
        Flight flight = new Flight(10000, new java.util.ArrayList<Integer>(java.util.Arrays.asList(10000)));
        CruisePlanner planner = new CruisePlanner();
        planner.plan(flight);
    }
}