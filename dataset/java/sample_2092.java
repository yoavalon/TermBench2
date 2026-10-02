import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_score;

    Particle(int dimensions) {
        Random rand = new Random();
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        best_position = new ArrayList<>();
        for (int i = 0; i < dimensions; i++) {
            position.add(rand.nextDouble() * 20 - 10);
            velocity.add(rand.nextDouble() * 2 - 1);
            best_position.add(position.get(i));
        }
        best_score = Double.MAX_VALUE;
    }
}

class Swarm {
    List<Particle> particles;
    List<Double> gbest_position;
    double gbest_score;

    Swarm(int num_particles, int dimensions) {
        particles = new ArrayList<>();
        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(dimensions));
        }
        gbest_position = new ArrayList<>();
        gbest_score = Double.MAX_VALUE;
    }

    void update_gbest() {
        for (Particle particle : particles) {
            if (particle.best_score < gbest_score) {
                gbest_score = particle.best_score;
                gbest_position = new ArrayList<>(particle.best_position);
            }
        }
    }

    void update_particles(double w, double c1, double c2) {
        Random rand = new Random();
        for (Particle particle : particles) {
            for (int i = 0; i < particle.position.size(); i++) {
                double r1 = rand.nextDouble();
                double r2 = rand.nextDouble();
                particle.velocity.set(i, w * particle.velocity.get(i) + c1 * r1 * (particle.best_position.get(i) - particle.position.get(i)) + c2 * r2 * (gbest_position.get(i) - particle.position.get(i)));
                particle.position.set(i, particle.position.get(i) + particle.velocity.get(i));
            }
        }
    }

    void evaluate(double[] objective_function(List<Double> x)) {
        for (Particle particle : particles) {
            double score = objective_function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = new ArrayList<>(particle.position);
            }
        }
    }
}

public class sample_2092 {
    static double[] objective_function(List<Double> x) {
        double[] result = new double[1];
        result[0] = x.stream().mapToDouble(xi -> xi * xi).sum();
        return result;
    }

    public static void main(String[] args) {
        int dimensions = 3;
        int num_particles = 20;
        double w = 0.7;
        double c1 = 1.5;
        double c2 = 1.5;
        int iterations = 100;
        Swarm swarm = new Swarm(num_particles, dimensions);
        for (int i = 0; i < iterations; i++) {
            swarm.update_gbest();
            swarm.update_particles(w, c1, c2);
            swarm.evaluate(sample_2092::objective_function);
        }
        System.out.println('Best score: ' + swarm.gbest_score);
        System.out.println('Best position: ' + swarm.gbest_position);
    }
}