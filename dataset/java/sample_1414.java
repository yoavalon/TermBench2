import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Swarm {
    int size;
    int dimensions;
    List<List<Double>> positions;
    List<List<Double>> velocities;
    List<List<Double>> best_positions;
    double best_score;

    public Swarm(int size, int dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.positions = new ArrayList<>();
        this.velocities = new ArrayList<>();
        this.best_positions = new ArrayList<>();
        this.best_score = Double.POSITIVE_INFINITY;
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            List<Double> pos = new ArrayList<>();
            List<Double> vel = new ArrayList<>();
            for (int j = 0; j < dimensions; j++) {
                pos.add(random.nextDouble());
                vel.add(random.nextDouble());
            }
            positions.add(pos);
            velocities.add(vel);
            best_positions.add(new ArrayList<>(pos));
        }
    }

    public void update_personal_best(double score) {
        if (score < best_score) {
            best_score = score;
            for (int i = 0; i < size; i++) {
                best_positions.get(i).clear();
                best_positions.get(i).addAll(positions.get(i));
            }
        }
    }

    public void update_velocity(List<Double> global_best) {
        double inertia = 0.5;
        double cognitive = 1.5;
        double social = 1.5;
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < dimensions; j++) {
                double r1 = random.nextDouble();
                double r2 = random.nextDouble();
                velocities.get(i).set(j, inertia * velocities.get(i).get(j) + cognitive * r1 * (best_positions.get(i).get(j) - positions.get(i).get(j)) + social * r2 * (global_best.get(j) - positions.get(i).get(j)));
            }
        }
    }

    public void update_position() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < dimensions; j++) {
                positions.get(i).set(j, positions.get(i).get(j) + velocities.get(i).get(j));
            }
        }
    }
}

class Environment {
    Swarm swarm;

    public Environment(Swarm swarm) {
        this.swarm = swarm;
    }

    public List<Double> evaluate() {
        List<Double> scores = new ArrayList<>();
        for (List<Double> position : swarm.positions) {
            double score = 0.0;
            for (double x : position) {
                score += Math.pow(x, 2);
            }
            scores.add(score);
        }
        return scores;
    }

    public List<Double> find_global_best(List<Double> scores) {
        int global_best_index = scores.indexOf(scores.stream().min(Double::compare).orElse(Double.POSITIVE_INFINITY));
        return swarm.positions.get(global_best_index);
    }
}

public class sample_1414 {
    public static void main(String[] args) {
        Swarm swarm = new Swarm(10, 3);
        Environment environment = new Environment(swarm);
        int iterations = 50;
        for (int _ = 0; _ < iterations; _++) {
            List<Double> scores = environment.evaluate();
            List<Double> global_best = environment.find_global_best(scores);
            swarm.update_personal_best(scores.stream().min(Double::compare).orElse(Double.POSITIVE_INFINITY));
            swarm.update_velocity(global_best);
            swarm.update_position();
        }
        System.out.println("Best score: " + swarm.best_score);
    }
}