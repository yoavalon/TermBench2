import java.util.Random;

class Environment {

    private String state;
    private final String goal_state = "C";
    private final Random random = new Random();

    public Environment() {
        this.state = random.choice(new String[]{"A", "B", "C"});
    }

    public String[] step(String action) {
        if (action.equals("move")) {
            if (state.equals("A")) {
                state = "B";
            } else if (state.equals("B")) {
                state = "C";
            }
            return new String[]{state, String.valueOf(_reward())};
        }
        return new String[]{state, "0"};
    }

    private int _reward() {
        return state.equals(goal_state) ? 1 : 0;
    }
}

class Agent {

    private Environment env;
    private String action = "move";

    public Agent(Environment env) {
        this.env = env;
    }

    public String[] act() {
        String[] result = env.step(action);
        return result;
    }
}

class Controller {

    private Agent agent;
    private int total_reward = 0;

    public Controller(Agent agent) {
        this.agent = agent;
    }

    public void run() {
        while (true) {
            String[] result = agent.act();
            total_reward += Integer.parseInt(result[1]);
            if (result[0].equals(agent.env.goal_state)) {
                System.out.println("Goal reached with total reward: " + total_reward);
            } else {
                System.out.println("Current state: " + result[0] + ", Reward: " + result[1]);
            }
        }
    }
}

public class sample_1738 {

    public static void main(String[] args) {
        Environment env = new Environment();
        Agent agent = new Agent(env);
        Controller controller = new Controller(agent);
        controller.run();
    }
}