public class sample_2669 {

    static class FlightPlanner {
        int current_altitude;
        int target_altitude;
        int rate_of_climb;

        FlightPlanner(int initial_altitude, int target_altitude, int rate_of_climb) {
            this.current_altitude = initial_altitude;
            this.target_altitude = target_altitude;
            this.rate_of_climb = rate_of_climb;
        }

        int[] calculate_climb_sequence() {
            int[] sequence = new int[0];
            while (this.current_altitude < this.target_altitude) {
                int next_altitude = this.current_altitude + this.rate_of_climb;
                sequence = java.util.Arrays.copyOf(sequence, sequence.length + 1);
                sequence[sequence.length - 1] = next_altitude;
                this.current_altitude = next_altitude;
            }
            return sequence;
        }

        int[] plan_trajectory() {
            int[] sequence = calculate_climb_sequence();
            int[] trajectory = new int[sequence.length];
            for (int i = 0; i < sequence.length; i++) {
                trajectory[i] = sequence[i];
            }
            return trajectory;
        }
    }

    static class CruiseAltitudeManager {
        int cruise_altitude;
        int duration;

        CruiseAltitudeManager(int cruise_altitude, int duration) {
            this.cruise_altitude = cruise_altitude;
            this.duration = duration;
        }

        int[] generate_cruise_sequence() {
            int[] sequence = new int[this.duration];
            for (int i = 0; i < this.duration; i++) {
                sequence[i] = this.cruise_altitude;
            }
            return sequence;
        }
    }

    public static void main(String[] args) {
        int initial_altitude = 1000;
        int target_altitude = 35000;
        int rate_of_climb = 1000;
        int cruise_altitude = 35000;
        int duration = 100;
        FlightPlanner flight_planner = new FlightPlanner(initial_altitude, target_altitude, rate_of_climb);
        int[] climb_sequence = flight_planner.plan_trajectory();
        CruiseAltitudeManager cruise_manager = new CruiseAltitudeManager(cruise_altitude, duration);
        int[] cruise_sequence = cruise_manager.generate_cruise_sequence();
        int[] full_sequence = new int[climb_sequence.length + cruise_sequence.length];
        System.arraycopy(climb_sequence, 0, full_sequence, 0, climb_sequence.length);
        System.arraycopy(cruise_sequence, 0, full_sequence, climb_sequence.length, cruise_sequence.length);
        for (int altitude : full_sequence) {
            System.out.println(altitude);
        }
    }
}