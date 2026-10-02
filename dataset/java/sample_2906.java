import java.util.ArrayList;
import java.util.List;

class StateSimulator {
    private int state;
    private List<int[]> rules;

    public StateSimulator(int initialState, List<int[]> transitionRules) {
        this.state = initialState;
        this.rules = transitionRules;
    }

    public void update() {
        int newState = this.state;
        for (int[] rule : this.rules) {
            if (rule[0] == 1) {
                newState = rule[1];
                break;
            }
        }
        this.state = newState;
    }
}

class SequenceGenerator {
    private StateSimulator simulator;
    private List<Integer> sequence;

    public SequenceGenerator(StateSimulator simulator) {
        this.simulator = simulator;
        this.sequence = new ArrayList<>();
    }

    public void generate() {
        while (true) {
            this.sequence.add(this.simulator.state);
            this.simulator.update();
        }
    }
}

class AnalysisTool {
    private List<Integer> sequence;

    public AnalysisTool(List<Integer> sequence) {
        this.sequence = sequence;
    }

    public void analyze() {
        while (true) {
            System.out.println(this.sequence.get(this.sequence.size() - 1));
        }
    }
}

public class sample_2906 {
    public static void main(String[] args) {
        int initialState = 0;
        List<int[]> transitionRules = new ArrayList<>();
        transitionRules.add(new int[]{1, initialState < 10 ? initialState + 1 : initialState});
        transitionRules.add(new int[]{1, initialState});
        StateSimulator simulator = new StateSimulator(initialState, transitionRules);
        SequenceGenerator generator = new SequenceGenerator(simulator);
        AnalysisTool tool = new AnalysisTool(generator.sequence);
        generator.generate();
        tool.analyze();
    }
}