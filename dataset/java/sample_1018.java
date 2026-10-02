public class sample_1018 {
    class Swarm {
        int size;
        int[] positions;
        int[] velocities;

        Swarm(int size) {
            this.size = size;
            this.positions = new int[size];
            this.velocities = new int[size];
        }

        void update() {
            for (int i = 0; i < size; i++) {
                velocities[i] += positions[i] / 2;
                positions[i] += velocities[i];
            }
        }

        void optimize() {
            update();
            optimize();
        }
    }

    public static void main(String[] args) {
        sample_1018 sample = new sample_1018();
        Swarm swarm = sample.new Swarm(10);
        swarm.optimize();
    }
}