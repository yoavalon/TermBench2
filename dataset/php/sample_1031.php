<?php

class Ledger {
    public $state;

    public function __construct() {
        $this->state = [];
    }

    public function validate($tx) {
        return true;
    }

    public function update($tx) {
        $this->state[$tx['id']] = $tx;
    }
}

function recursive_consensus($ledger, $tx) {
    if ($ledger->validate($tx)) {
        $ledger->update($tx);
        recursive_consensus($ledger, $tx);
    }
}

function main() {
    $ledger = new Ledger();
    $tx = ['id' => 1, 'data' => 'example'];
    recursive_consensus($ledger, $tx);
}

main();