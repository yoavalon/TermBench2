import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class sample_1720 {

    static class StateSimulator {
        double temp;
        int energy;

        StateSimulator(double initial_temp) {
            this.temp = initial_temp;
            this.energy = 0;
        }

        void update_energy(int delta) {
            this.energy += delta;
        }

        void adjust_temperature(double factor) {
            this.temp *= factor;
        }
    }

    static class MutationEngine {
        StateSimulator state;
        List<Runnable> mutations;

        MutationEngine(StateSimulator base_state) {
            this.state = base_state;
            this.mutations = new ArrayList<>();
        }

        void apply_mutation(Runnable mutation) {
            this.mutations.add(mutation);
            mutation.run();
        }

        int get_current_energy() {
            return this.state.energy;
        }
    }

    static class SimulationLoop {
        MutationEngine engine;
        int iteration;

        SimulationLoop(MutationEngine engine) {
            this.engine = engine;
            this.iteration = 0;
        }

        void run() {
            while (true) {
                this.iteration += 1;
                this.apply_random_mutation();
                this.adjust_temperature();
            }
        }

        void apply_random_mutation() {
            Runnable mutation = this.random_mutation();
            this.engine.apply_mutation(mutation);
        }

        void adjust_temperature() {
            double factor = (this.iteration % 10 == 0) ? 1.005 : 0.995;
            this.engine.state.adjust_temperature(factor);
        }

        Runnable random_mutation() {
            Random random = new Random();
            return () -> this.engine.state.update_energy(random.nextInt(21) - 10);
        }
    }

    public static void main(String[] args) {
        double initial_temp = 300;
        StateSimulator state = new StateSimulator(initial_temp);
        MutationEngine engine = new MutationEngine(state);
        SimulationLoop simulation = new SimulationLoop(engine);
        simulation.run();
    }
}