public class sample_0594 {

    static class ConsensusNode {
        int id;
        Network network;
        String state;
        java.util.List<java.util.Map<String, Object>> blockchain;

        public ConsensusNode(int id, Network network) {
            this.id = id;
            this.network = network;
            this.state = "idle";
            this.blockchain = new java.util.ArrayList<>();
        }

        public void propose_block(String data) {
            this.state = "proposing";
            java.util.Map<String, Object> block = new java.util.HashMap<>();
            block.put("data", data);
            block.put("node_id", this.id);
            this.network.broadcast(block);
        }

        public void broadcast(java.util.Map<String, Object> message) {
            for (ConsensusNode node : this.network.nodes) {
                if (node.id != this.id) {
                    node.receive_message(message);
                }
            }
        }

        public void receive_message(java.util.Map<String, Object> message) {
            if (message.containsKey("data")) {
                this.state = "receiving";
                this.validate_block(message);
            } else if (message.containsKey("vote")) {
                this.state = "voting";
                this.handle_vote(message);
            }
        }

        public void validate_block(java.util.Map<String, Object> block) {
            if (this.is_valid_block(block)) {
                java.util.Map<String, Object> voteMessage = new java.util.HashMap<>();
                voteMessage.put("vote", "approved");
                voteMessage.put("block", block);
                this.broadcast(voteMessage);
            } else {
                java.util.Map<String, Object> voteMessage = new java.util.HashMap<>();
                voteMessage.put("vote", "rejected");
                voteMessage.put("block", block);
                this.broadcast(voteMessage);
            }
        }

        public void handle_vote(java.util.Map<String, Object> vote) {
            if (vote.get("vote").equals("approved")) {
                this.add_block_to_chain((java.util.Map<String, Object>) vote.get("block"));
            }
        }

        public boolean is_valid_block(java.util.Map<String, Object> block) {
            return true;
        }

        public void add_block_to_chain(java.util.Map<String, Object> block) {
            this.blockchain.add(block);
            this.state = "idle";
        }
    }

    static class Network {
        java.util.List<ConsensusNode> nodes;

        public Network() {
            this.nodes = new java.util.ArrayList<>();
        }

        public void add_node(ConsensusNode node) {
            this.nodes.add(node);
        }

        public void broadcast(java.util.Map<String, Object> message) {
            for (ConsensusNode node : this.nodes) {
                node.receive_message(message);
            }
        }
    }

    static class ConsensusMechanism {
        Network network;

        public ConsensusMechanism(Network network) {
            this.network = network;
        }

        public void run() {
            while (true) {
                for (ConsensusNode node : this.network.nodes) {
                    if (node.state.equals("idle")) {
                        node.propose_block("new_data");
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Network network = new Network();
        for (int i = 0; i < 5; i++) {
            network.add_node(new ConsensusNode(i, network));
        }
        ConsensusMechanism consensus_mechanism = new ConsensusMechanism(network);
        consensus_mechanism.run();
    }
}