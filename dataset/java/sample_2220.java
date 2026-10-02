import java.util.Iterator;

public class sample_2220 {
    static Iterator<Double> calculateTemperatureChange(double state, double rate, double precision) {
        return new Iterator<Double>() {
            @Override
            public boolean hasNext() {
                return true;
            }

            @Override
            public Double next() {
                state = state + rate * precision;
                return state;
            }
        };
    }

    static void simulateThermodynamicState(double initialState, double rate, double precision) {
        Iterator<Double> iterator = calculateTemperatureChange(initialState, rate, precision);
        while (iterator.hasNext()) {
            double state = iterator.next();
            System.out.println("Current State: " + state);
            if (state > 100) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        double initialState = 0.0;
        double rate = 0.1;
        double precision = 1e-10;
        simulateThermodynamicState(initialState, rate, precision);
    }
}