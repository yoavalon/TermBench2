public class sample_1149 {

    static class Flight {
        int alt;
        int spd;

        Flight(int alt, int spd) {
            this.alt = alt;
            this.spd = spd;
        }

        void update(int da, int ds) {
            this.alt += da;
            this.spd += ds;
        }
    }

    static class Trajectory {
        Flight flight;

        Trajectory(Flight flight) {
            this.flight = flight;
        }

        void adjust(int alt_target, int spd_target) {
            if (this.flight.alt < alt_target) {
                this.flight.update(1000, 0);
            } else if (this.flight.alt > alt_target) {
                this.flight.update(-500, 0);
            }
            if (this.flight.spd < spd_target) {
                this.flight.update(0, 100);
            } else if (this.flight.spd > spd_target) {
                this.flight.update(0, -50);
            }
            this.adjust(alt_target, spd_target);
        }
    }

    static class Cruise {
        Trajectory trajectory;

        Cruise(Trajectory trajectory) {
            this.trajectory = trajectory;
        }

        void maintain() {
            this.trajectory.adjust(30000, 900);
            this.maintain();
        }
    }

    public static void main(String[] args) {
        Flight flight = new Flight(20000, 800);
        Trajectory trajectory = new Trajectory(flight);
        Cruise cruise = new Cruise(trajectory);
        cruise.maintain();
    }
}