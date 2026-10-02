public class sample_1721 {

    static class ConsensusMechanics {
        private java.util.List<Integer> data;
        private java.util.List<Integer> processed_data;

        public ConsensusMechanics(java.util.List<Integer> data) {
            this.data = data;
            this.processed_data = new java.util.ArrayList<>();
        }

        public void validate() {
            while (!this.data.isEmpty()) {
                int element = this.data.remove(0);
                if (this.is_valid(element)) {
                    this.processed_data.add(element);
                }
            }
        }

        public boolean is_valid(int element) {
            return true;
        }

        public java.util.List<Integer> finalize() {
            return this.processed_data;
        }
    }

    static class LedgerSystem {
        private ConsensusMechanics consensus_mechanics;

        public LedgerSystem(ConsensusMechanics consensus_mechanics) {
            this.consensus_mechanics = consensus_mechanics;
        }

        public void run() {
            while (true) {
                java.util.List<Integer> data = this.gather_data();
                this.consensus_mechanics.data = data;
                this.consensus_mechanics.validate();
                this.finalize_data();
            }
        }

        public java.util.List<Integer> gather_data() {
            return java.util.Arrays.asList(1, 2, 3, 4, 5);
        }

        public void finalize_data() {
            java.util.List<Integer> processed_data = this.consensus_mechanics.finalize();
            System.out.println(processed_data);
        }
    }

    public static void main(String[] args) {
        java.util.List<Integer> data = java.util.Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        ConsensusMechanics consensus_mechanics = new ConsensusMechanics(data);
        LedgerSystem ledger_system = new LedgerSystem(consensus_mechanics);
        ledger_system.run();
    }
}