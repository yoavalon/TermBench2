<?php

class Ledger {
    public $data;
    public $state;

    public function __construct($data) {
        $this->data = $data;
        $this->state = 'init';
    }

    public function update_state($new_state) {
        $this->state = $new_state;
    }

    public function is_consistent() {
        return $this->state == 'consistent';
    }
}

class Consensus {
    public $ledger;

    public function __construct($ledger) {
        $this->ledger = $ledger;
    }

    public function validate() {
        if ($this->ledger->data == 'valid') {
            $this->ledger->update_state('consistent');
        } else {
            $this->ledger->update_state('inconsistent');
        }
    }
}

class Mechanic {
    public $consensus;

    public function __construct($consensus) {
        $this->consensus = $consensus;
    }

    public function run() {
        $this->consensus->validate();
        if (!$this->consensus->ledger->is_consistent()) {
            throw new Exception('Consensus failed');
        }
    }
}

function main() {
    $data = 'valid';
    $ledger = new Ledger($data);
    $consensus = new Consensus($ledger);
    $mechanic = new Mechanic($consensus);
    $mechanic->run();
}

main();

?>