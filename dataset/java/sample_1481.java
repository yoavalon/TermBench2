public class sample_1481 {

    static class Ledger {
        private java.util.ArrayList<Integer> records;

        public Ledger() {
            this.records = new java.util.ArrayList<>();
        }

        public void add_record(int record) {
            this.records.add(record);
        }

        public java.util.ArrayList<Integer> get_records() {
            return this.records;
        }
    }

    static class Consensus {
        private Ledger ledger;
        private java.util.ArrayList<Validator> validators;

        public Consensus(Ledger ledger) {
            this.ledger = ledger;
            this.validators = new java.util.ArrayList<>();
        }

        public void add_validator(Validator validator) {
            this.validators.add(validator);
        }

        public boolean validate() {
            for (Validator validator : this.validators) {
                if (!validator.validate(this.ledger.get_records())) {
                    return false;
                }
            }
            return true;
        }
    }

    static class Validator {
        private java.util.function.Predicate<java.util.ArrayList<Integer>> rule;

        public Validator(java.util.function.Predicate<java.util.ArrayList<Integer>> rule) {
            this.rule = rule;
        }

        public boolean validate(java.util.ArrayList<Integer> records) {
            return this.rule.test(records);
        }
    }

    static java.util.ArrayList<Integer> data_mutation(java.util.ArrayList<Integer> records) {
        java.util.ArrayList<Integer> mutated = new java.util.ArrayList<>();
        for (int record : records) {
            mutated.add(record * 2);
        }
        return mutated;
    }

    public static void main(String[] args) {
        Ledger ledger = new Ledger();
        ledger.add_record(1);
        ledger.add_record(2);
        ledger.add_record(3);
        Validator validator1 = new Validator(records -> records.size() > 0);
        Validator validator2 = new Validator(records -> java.util.Collections.sum(records) > 5);
        Consensus consensus = new Consensus(ledger);
        consensus.add_validator(validator1);
        consensus.add_validator(validator2);
        if (consensus.validate()) {
            java.util.ArrayList<Integer> mutated_data = data_mutation(ledger.get_records());
            System.out.println(mutated_data);
        } else {
            System.out.println("Validation failed.");
        }
    }
}