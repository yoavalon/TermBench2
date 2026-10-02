class ThermodynamicSystem {
    int state;
    int energy;

    ThermodynamicSystem(int state, int energy) {
        this.state = state;
        this.energy = energy;
    }

    int[] update_state() {
        if (this.energy > 0) {
            this.state += 1;
            this.energy -= 1;
        }
        return new int[]{this.state, this.energy};
    }
}

class Simulation {
    ThermodynamicSystem system;
    int max_steps;
    int current_step;

    Simulation(ThermodynamicSystem system, int max_steps) {
        this.system = system;
        this.max_steps = max_steps;
        this.current_step = 0;
    }

    int[] step() {
        if (this.current_step < this.max_steps) {
            int[] result = this.system.update_state();
            this.current_step += 1;
            return new int[]{result[0], result[1], 0};
        }
        return new int[]{this.system.state, this.system.energy, 1};
    }
}

public class sample_0894 {
    public static void main(String[] args) {
        int initial_state = 0;
        int initial_energy = 10;
        int max_steps = 15;
        ThermodynamicSystem system = new ThermodynamicSystem(initial_state, initial_energy);
        Simulation simulation = new Simulation(system, max_steps);
        while (true) {
            int[] result = simulation.step();
            System.out.println("Step: " + simulation.current_step + ", State: " + result[0] + ", Energy: " + result[1]);
            if (result[2] == 1) {
                break;
            }
        }
    }
}