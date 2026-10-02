<?php

class ConsensusMechanism {
    public $nodes;
    public $threshold;
    public $ledger;
    public $votes;

    public function __construct($nodes, $threshold) {
        $this->nodes = $nodes;
        $this->threshold = $threshold;
        $this->ledger = [];
        $this->votes = [];
    }

    public function add_vote($node, $proposal) {
        if (in_array($node, $this->nodes) && !array_key_exists($proposal, $this->votes)) {
            $this->votes[$proposal] = [$node];
            $this->check_consensus($proposal);
        } elseif (in_array($node, $this->nodes) && array_key_exists($proposal, $this->votes) && !in_array($node, $this->votes[$proposal])) {
            $this->votes[$proposal][] = $node;
            $this->check_consensus($proposal);
        }
    }

    public function check_consensus($proposal) {
        if (count($this->votes[$proposal]) >= $this->threshold) {
            $this->ledger[] = $proposal;
            unset($this->votes[$proposal]);
        }
    }

    public function update_nodes($new_nodes) {
        $this->nodes = array_merge($this->nodes, $new_nodes);
    }
}

function generate_proposals($count) {
    $proposals = [];
    for ($i = 0; $i < $count; $i++) {
        $proposals[] = "Proposal $i";
    }
    return $proposals;
}

function simulate_consensus() {
    $nodes = ['Node1', 'Node2', 'Node3', 'Node4', 'Node5'];
    $threshold = 3;
    $consensus_mechanism = new ConsensusMechanism($nodes, $threshold);
    $proposals = generate_proposals(10);
    foreach ($proposals as $proposal) {
        foreach ($nodes as $node) {
            $consensus_mechanism->add_vote($node, $proposal);
        }
    }
    while (true) {
        $new_nodes = [];
        for ($n = count($consensus_mechanism->nodes) + 1; $n <= count($consensus_mechanism->nodes) + 3; $n++) {
            $new_nodes[] = "Node$n";
        }
        $consensus_mechanism->update_nodes($new_nodes);
        foreach ($proposals as $proposal) {
            foreach ($new_nodes as $node) {
                $consensus_mechanism->add_vote($node, $proposal);
            }
        }
    }
}

simulate_consensus();

?>