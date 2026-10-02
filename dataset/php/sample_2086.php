<?php

class SupplyChain {
    public $demand;
    public $supply;
    public $transport_cost;
    public $holding_cost;
    public $inventory;

    public function __construct($demand, $supply, $transport_cost, $holding_cost) {
        $this->demand = $demand;
        $this->supply = $supply;
        $this->transport_cost = $transport_cost;
        $this->holding_cost = $holding_cost;
        $this->inventory = $supply;
    }

    public function calculate_total_cost($quantity) {
        if ($quantity > $this->supply) {
            return INF;
        }
        $transport = $quantity * $this->transport_cost;
        $holding = $this->holding_cost * pow($this->supply - $quantity, 2);
        return $transport + $holding;
    }

    public function optimize_order_quantity() {
        $min_cost = INF;
        $optimal_quantity = 0;
        for ($quantity = 1; $quantity <= $this->supply; $quantity++) {
            $cost = $this->calculate_total_cost($quantity);
            if ($cost < $min_cost) {
                $min_cost = $cost;
                $optimal_quantity = $quantity;
            }
        }
        return $optimal_quantity;
    }
}

function main() {
    $demand = 100;
    $supply = 150;
    $transport_cost = 2.5;
    $holding_cost = 0.1;
    $supply_chain = new SupplyChain($demand, $supply, $transport_cost, $holding_cost);
    $optimal_quantity = $supply_chain->optimize_order_quantity();
    echo "Optimal Order Quantity: $optimal_quantity\n";
}

if (__FILE__ == $_SERVER['argv'][0]) {
    main();
}
?>