import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Particle {
    List<Double> position;
    List<Double> velocity;
    List<Double> best_position;
    double best_score;

    Particle(int dimensions, double[] bounds) {
        position = new ArrayList<>();
        velocity = new ArrayList<>();
        best_position = new ArrayList<>();
        for (int i = 0; i < dimensions; i++) {
            position.add(bounds[0] + (bounds[1] - bounds[0]) * new Random().nextDouble());
            velocity.add(0.0);
            best_position.add(position.get(i));
        }
        best_score = Double.MAX_VALUE;
    }
}

class Swarm {
    List<Particle> particles;
    double[] bounds;
    java.util.function.Function<List<Double>, Double> function;
    double w;
    double c1;
    double c2;
    List<Double> best_swarm_position;
    double best_swarm_score;

    Swarm(List<Particle> particles, double[] bounds, java.util.function.Function<List<Double>, Double> function, double w, double c1, double c2) {
        this.particles = particles;
        this.bounds = bounds;
        this.function = function;
        this.w = w;
        this.c1 = c1;
        this.c2 = c2;
        best_swarm_position = new ArrayList<>();
        best_swarm_score = Double.MAX_VALUE;
        for (int i = 0; i < bounds.length; i++) {
            best_swarm_position.add(0.0);
        }
    }

    void evaluate() {
        for (Particle particle : particles) {
            double score = function.apply(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = new ArrayList<>(particle.position);
            }
            if (score < best_swarm_score) {
                best_swarm_score = score;
                best_swarm_position = new ArrayList<>(particle.position);
            }
        }
    }

    void update() {
        for (Particle particle : particles) {
            for (int i = 0; i < particle.position.size(); i++) {
                double r1 = new Random().nextDouble();
                double r2 = new Random().nextDouble();
                double velocity_cognitive = c1 * r1 * (particle.best_position.get(i) - particle.position.get(i));
                double velocity_social = c2 * r2 * (best_swarm_position.get(i) - particle.position.get(i));
                particle.velocity.set(i, w * particle.velocity.get(i) + velocity_cognitive + velocity_social);
                particle.position.set(i, particle.position.get(i) + particle.velocity.get(i));
                particle.position.set(i, Math.max(bounds[0], Math.min(bounds[1], particle.position.get(i))));
            }
        }
    }
}

class sample_0845 {
    static double objective_function(List<Double> x) {
        double sum = 0.0;
        for (double xi : x) {
            sum += xi * xi;
        }
        return sum;
    }

    static List<Object> optimize(int dimensions, double[] bounds, int num_particles, int max_iterations, double w, double c1, double c2) {
        List<Particle> particles = new ArrayList<>();
        for (int i = 0; i < num_particles; i++) {
            particles.add(new Particle(dimensions, bounds));
        }
        Swarm swarm = new Swarm(particles, bounds, sample_0845::objective_function, w, c1, c2);
        for (int i = 0; i < max_iterations; i++) {
            swarm.evaluate();
            swarm.update();
        }
        List<Object> result = new ArrayList<>();
        result.add(swarm.best_swarm_position);
        result.add(swarm.best_swarm_score);
        return result;
    }

    public static void main(String[] args) {
        int dimensions = 2;
        double[] bounds = {-10, 10};
        int num_particles = 30;
        int max_iterations = 100;
        double w = 0.729;
        double c1 = 1.494;
        double c2 = 1.494;
        List<Object> result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2);
        System.out.println("Best position: " + result.get(0));
        System.out.println("Best score: " + result.get(1));
    }
}