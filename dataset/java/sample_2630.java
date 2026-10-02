public class sample_2630 {

    static class SequenceGenerator {
        int start;
        int step;
        int count;
        int current;
        int index;

        SequenceGenerator(int start, int step, int count) {
            this.start = start;
            this.step = step;
            this.count = count;
            this.current = start;
            this.index = 0;
        }

        Integer next() {
            if (index < count) {
                int value = current;
                current += step;
                index += 1;
                return value;
            } else {
                return null;
            }
        }
    }

    static class FlightTrajectory {
        int initial_altitude;
        int rate_of_climb;
        int cruise_altitude;
        int descent_rate;
        SequenceGenerator sequence;
        int current_altitude;

        FlightTrajectory(int initial_altitude, int rate_of_climb, int cruise_altitude, int descent_rate, SequenceGenerator sequence) {
            this.initial_altitude = initial_altitude;
            this.rate_of_climb = rate_of_climb;
            this.cruise_altitude = cruise_altitude;
            this.descent_rate = descent_rate;
            this.sequence = sequence;
            this.current_altitude = initial_altitude;
        }

        void plan_cruise() {
            SequenceGenerator climb_sequence = new SequenceGenerator(initial_altitude, rate_of_climb, 100);
            while (true) {
                Integer next_altitude = climb_sequence.next();
                if (next_altitude == null || next_altitude >= cruise_altitude) {
                    break;
                }
                current_altitude = next_altitude;
            }
            if (current_altitude < cruise_altitude) {
                current_altitude = cruise_altitude;
            }
            SequenceGenerator descent_sequence = new SequenceGenerator(current_altitude, -descent_rate, 100);
            while (true) {
                Integer next_altitude = descent_sequence.next();
                if (next_altitude == null || next_altitude <= 0) {
                    break;
                }
                current_altitude = next_altitude;
            }
            if (current_altitude > 0) {
                current_altitude = 0;
            }
        }
    }

    public static void main(String[] args) {
        SequenceGenerator sequence = new SequenceGenerator(0, 100, 200);
        FlightTrajectory trajectory = new FlightTrajectory(1000, 500, 30000, 200, sequence);
        trajectory.plan_cruise();
        System.out.println("Final Altitude: " + trajectory.current_altitude);
    }
}