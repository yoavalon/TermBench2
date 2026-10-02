import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    double[] position;
    double[] velocity;
    double[] best_position;
    double best_fitness;

    Particle(int dimensions) {
        this.position = new double[dimensions];
        this.velocity = new double[dimensions];
        this.best_position = new double[dimensions];
        Random rand = new Random();
        for (int i = 0; i < dimensions; i++) {
            position[i] = rand.nextDouble() * 2 - 1;
            velocity[i] = rand.nextDouble() * 2 - 1;
        }
        best_fitness = Double.POSITIVE_INFINITY;
        for (int i = 0; i < dimensions; i++) {
            best_position[i] = position[i];
        }
    }
}

class PSO {
    int dimensions;
    List<Particle> population;
    double[] gbest_position;
    double gbest_fitness;
    double omega;
    double phi_p;
    double phi_g;

    PSO(int dimensions, int population_size, double omega, double phi_p, double phi_g) {
        this.dimensions = dimensions;
        this.population = new ArrayList<>();
        for (int i = 0; i < population_size; i++) {
            population.add(new Particle(dimensions));
        }
        this.gbest_position = new double[dimensions];
        this.gbest_fitness = Double.POSITIVE_INFINITY;
        this.omega = omega;
        this.phi_p = phi_p;
        this.phi_g = phi_g;
    }

    void update_global_best() {
        for (Particle particle : population) {
            double fitness = fitness(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                for (int i = 0; i < dimensions; i++) {
                    particle.best_position[i] = particle.position[i];
                }
            }
            if (fitness < gbest_fitness) {
                gbest_fitness = fitness;
                for (int i = 0; i < dimensions; i++) {
                    gbest_position[i] = particle.position[i];
                }
            }
        }
    }

    void update_velocity(Particle particle) {
        Random rand = new Random();
        for (int i = 0; i < dimensions; i++) {
            double r_p = rand.nextDouble();
            double r_g = rand.nextDouble();
            double cognitive = phi_p * r_p * (particle.best_position[i] - particle.position[i]);
            double social = phi_g * r_g * (gbest_position[i] - particle.position[i]);
            particle.velocity[i] = omega * particle.velocity[i] + cognitive + social;
        }
    }

    void update_position(Particle particle) {
        for (int i = 0; i < dimensions; i++) {
            particle.position[i] += particle.velocity[i];
        }
    }

    double fitness(double[] position) {
        double sum = 0;
        for (double x : position) {
            sum += x * x;
        }
        return sum;
    }

    void run() {
        while (true) {
            update_global_best();
            for (Particle particle : population) {
                update_velocity(particle);
                update_position(particle);
            }
        }
    }
}

public class sample_2923 {
    public static void main(String[] args) {
        int dimensions = 2;
        int population_size = 10;
        double omega = 0.7;
        double phi_p = 1.5;
        double phi_g = 1.5;
        PSO pso = new PSO(dimensions, population_size, omega, phi_p, phi_g);
        pso.run();
    }
}