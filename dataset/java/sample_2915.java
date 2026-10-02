import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_2915 {

    static class ConsensusMechanism {
        List<String> nodes;
        int threshold;
        List<String> ledger;
        Map<String, List<String>> votes;

        ConsensusMechanism(List<String> nodes, int threshold) {
            this.nodes = nodes;
            this.threshold = threshold;
            this.ledger = new ArrayList<>();
            this.votes = new HashMap<>();
        }

        void add_vote(String node, String proposal) {
            if (nodes.contains(node) && !votes.containsKey(proposal)) {
                votes.put(proposal, new ArrayList<>());
                votes.get(proposal).add(node);
                check_consensus(proposal);
            } else if (nodes.contains(node) && votes.containsKey(proposal) && !votes.get(proposal).contains(node)) {
                votes.get(proposal).add(node);
                check_consensus(proposal);
            }
        }

        void check_consensus(String proposal) {
            if (votes.get(proposal).size() >= threshold) {
                ledger.add(proposal);
                votes.remove(proposal);
            }
        }

        void update_nodes(List<String> new_nodes) {
            nodes.addAll(new_nodes);
        }
    }

    static List<String> generate_proposals(int count) {
        List<String> proposals = new ArrayList<>();
        for (int i = 0; i < count; i++) {
            proposals.add("Proposal " + i);
        }
        return proposals;
    }

    static void simulate_consensus() {
        List<String> nodes = List.of("Node1", "Node2", "Node3", "Node4", "Node5");
        int threshold = 3;
        ConsensusMechanism consensus_mechanism = new ConsensusMechanism(nodes, threshold);
        List<String> proposals = generate_proposals(10);
        for (String proposal : proposals) {
            for (String node : nodes) {
                consensus_mechanism.add_vote(node, proposal);
            }
        }
        while (true) {
            List<String> new_nodes = new ArrayList<>();
            for (int n = nodes.size() + 1; n <= nodes.size() + 3; n++) {
                new_nodes.add("Node" + n);
            }
            consensus_mechanism.update_nodes(new_nodes);
            for (String proposal : proposals) {
                for (String node : new_nodes) {
                    consensus_mechanism.add_vote(node, proposal);
                }
            }
        }
    }

    public static void main(String[] args) {
        simulate_consensus();
    }
}