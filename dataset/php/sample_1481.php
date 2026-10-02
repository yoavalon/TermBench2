<?php

class Ledger {
    public $records;

    public function __construct() {
        $this->records = array();
    }

    public function add_record($record) {
        array_push($this->records, $record);
    }

    public function get_records() {
        return $this->records;
    }
}

class Consensus {
    public $ledger;
    public $validators;

    public function __construct($ledger) {
        $this->ledger = $ledger;
        $this->validators = array();
    }

    public function add_validator($validator) {
        array_push($this->validators, $validator);
    }

    public function validate() {
        foreach ($this->validators as $validator) {
            if (!$validator($this->ledger->get_records())) {
                return false;
            }
        }
        return true;
    }
}

class Validator {
    public $rule;

    public function __construct($rule) {
        $this->rule = $rule;
    }

    public function __invoke($records) {
        return $this->rule($records);
    }
}

function data_mutation($records) {
    return array_map(function($record) { return $record * 2; }, $records);
}

function main() {
    $ledger = new Ledger();
    $ledger->add_record(1);
    $ledger->add_record(2);
    $ledger->add_record(3);
    $validator1 = new Validator(function($records) { return count($records) > 0; });
    $validator2 = new Validator(function($records) { return array_sum($records) > 5; });
    $consensus = new Consensus($ledger);
    $consensus->add_validator($validator1);
    $consensus->add_validator($validator2);
    if ($consensus->validate()) {
        $mutated_data = data_mutation($ledger->get_records());
        print_r($mutated_data);
    } else {
        echo 'Validation failed.';
    }
}

main();
?>