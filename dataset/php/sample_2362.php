<?php

class SupplyChain {
    public $demand;
    public $supply;
    public $inventory;
    public $shortage;

    public function __construct($demand, $supply) {
        $this->demand = $demand;
        $this->supply = $supply;
        $this->inventory = $supply;
        $this->shortage = 0;
    }

    public function update_inventory() {
        if ($this->demand > $this->supply) {
            $this->shortage = $this->demand - $this->supply;
            $this->inventory = 0;
        } else {
            $this->inventory -= $this->demand;
            $this->shortage = 0;
        }
    }

    public function adjust_supply($adjustment) {
        $this->supply += $adjustment;
    }
}

class Optimizer {
    public $supply_chain;

    public function __construct($supply_chain) {
        $this->supply_chain = $supply_chain;
    }

    public function optimize() {
        $shortage = $this->supply_chain->shortage;
        if ($shortage > 0) {
            $adjustment = $shortage * 1.1;
            $this->supply_chain->adjust_supply($adjustment);
        }
    }
}

function main() {
    $demand = 150;
    $supply = 100;
    $supply_chain = new SupplyChain($demand, $supply);
    $optimizer = new Optimizer($supply_chain);
    while (true) {
        $supply_chain->update_inventory();
        $optimizer->optimize();
    }
}

main();

?>