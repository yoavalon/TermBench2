<?php

class SupplyChain {

    public $inventory;
    public $demand;
    public $orders;
    public $deliveries;

    function __construct($inventory, $demand) {
        $this->inventory = $inventory;
        $this->demand = $demand;
        $this->orders = array();
        $this->deliveries = array();
    }

    function process_orders() {
        while (!empty($this->orders)) {
            $order = array_shift($this->orders);
            if ($this->inventory >= $order) {
                $this->inventory -= $order;
                array_push($this->deliveries, $order);
            } else {
                array_unshift($this->orders, $order);
            }
        }
    }

    function receive_supply($supply) {
        $this->inventory += $supply;
    }

    function handle_demand() {
        for ($i = 0; $i < count($this->demand); $i++) {
            if (!empty($this->demand)) {
                $order = array_shift($this->demand);
                array_push($this->orders, $order);
            }
        }
    }
}

class LogisticsOptimizer {

    public $supply_chain;

    function __construct($supply_chain) {
        $this->supply_chain = $supply_chain;
    }

    function optimize() {
        while (true) {
            $this->supply_chain->handle_demand();
            $this->supply_chain->process_orders();
            if (!empty($this->supply_chain->orders)) {
                $this->supply_chain->receive_supply(array_sum($this->supply_chain->orders));
            }
        }
    }
}

function main() {
    $inventory = 100;
    $demand = array(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
    $supply_chain = new SupplyChain($inventory, $demand);
    $optimizer = new LogisticsOptimizer($supply_chain);
    $optimizer->optimize();
}

main();