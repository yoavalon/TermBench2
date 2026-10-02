php
<?php

class Sequence {
    public $value;
    public $step;

    function __construct($start, $step) {
        $this->value = $start;
        $this->step = $step;
    }

    function next() {
        $this->value += $this->step;
        return $this->value;
    }
}

class Consensus {
    public $sequence;
    public $validators;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->validators = array();
    }

    function add_validator($validator) {
        array_push($this->validators, $validator);
    }

    function validate() {
        $value = $this->sequence->next();
        foreach ($this->validators as $validator) {
            if (!$validator($value)) {
                return false;
            }
        }
        return true;
    }
}

class Ledger {
    public $records;

    function __construct() {
        $this->records = array();
    }

    function record($value) {
        array_push($this->records, $value);
    }
}

function main() {
    $seq = new Sequence(0, 1);
    $consensus = new Consensus($seq);
    $ledger = new Ledger();

    function validator1($x) {
        return $x % 2 == 0;
    }

    function validator2($x) {
        return $x > 0;
    }

    $consensus->add_validator("validator1");
    $consensus->add_validator("validator2");

    while (true) {
        if ($consensus->validate()) {
            $ledger->record($seq->value);
        }
    }
}

main();
?>