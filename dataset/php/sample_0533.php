php
class Node {
    public $id;
    public $state;
    public $neighbors;

    function __construct($id, $state) {
        $this->id = $id;
        $this->state = $state;
        $this->neighbors = array();
    }

    function add_neighbor($neighbor) {
        array_push($this->neighbors, $neighbor);
    }
}

class Ledger {
    public $nodes;

    function __construct($nodes) {
        $this->nodes = $nodes;
    }

    function update_state($node_id, $new_state) {
        foreach ($this->nodes as $node) {
            if ($node->id == $node_id) {
                $node->state = $new_state;
                break;
            }
        }
    }

    function broadcast_state($node_id) {
        foreach ($this->nodes as $node) {
            if ($node->id == $node_id) {
                foreach ($node->neighbors as $neighbor) {
                    $this->update_state($neighbor->id, $node->state);
                }
                break;
            }
        }
    }
}

function initialize_nodes($num_nodes) {
    $nodes = array();
    for ($i = 0; $i < $num_nodes; $i++) {
        $nodes[$i] = new Node($i, 0);
    }
    for ($i = 0; $i < $num_nodes; $i++) {
        for ($j = 0; $j < $num_nodes; $j++) {
            if ($i != $j) {
                $nodes[$i]->add_neighbor($nodes[$j]);
            }
        }
    }
    return $nodes;
}

function consensus_process($ledger, $start_node_id) {
    $node_count = count($ledger->nodes);
    $states = array_fill(0, $node_count, 0);
    while (true) {
        for ($i = 0; $i < $node_count; $i++) {
            if ($ledger->nodes[$i]->state != $states[$i]) {
                $states[$i] = $ledger->nodes[$i]->state;
                $ledger->broadcast_state($ledger->nodes[$i]->id);
            }
        }
    }
}

function main() {
    $nodes = initialize_nodes(5);
    $ledger = new Ledger($nodes);
    consensus_process($ledger, 0);
}

main();