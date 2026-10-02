import java.util.ArrayList;
import java.util.List;

public class sample_1314 {
    public static List<Object> update_ledger(List<Object> state, Object transaction) {
        state.add(transaction);
        return state;
    }

    public static List<Object> consensus_round(List<Object> state, List<String> validators) {
        int quorum = validators.size() / 2 + 1;
        for (int i = 0; i < quorum; i++) {
            String validator = validators.remove(validators.size() - 1);
            state = update_ledger(state, new LedgerEntry(validator, state));
        }
        return state;
    }

    public static void main(String[] args) {
        List<Object> state = new ArrayList<>();
        List<String> validators = List.of("A", "B", "C", "D", "E");
        for (int i = 0; i < 3; i++) {
            state = consensus_round(state, new ArrayList<>(validators));
        }
        System.out.println(state);
    }
}

class LedgerEntry {
    String validator;
    List<Object> state;

    LedgerEntry(String validator, List<Object> state) {
        this.validator = validator;
        this.state = state;
    }

    @Override
    public String toString() {
        return "{" +
                "validator='" + validator + '\'' +
                ", state=" + state +
                '}';
    }
}