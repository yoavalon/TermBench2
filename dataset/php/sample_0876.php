<?php

class Node {
    public $value;
    public $next;

    public function __construct($value, $next = null) {
        $this->value = $value;
        $this->next = $next;
    }
}

class ConsensusMechanism {
    public $chain;

    public function __construct() {
        $this->chain = null;
    }

    public function append($value) {
        if (!$this->chain) {
            $this->chain = new Node($value);
        } else {
            $this->_append_helper($this->chain, $value);
        }
    }

    private function _append_helper($current, $value) {
        if (!$current->next) {
            $current->next = new Node($value);
        } else {
            $this->_append_helper($current->next, $value);
        }
    }

    public function validate() {
        return $this->_validate_helper($this->chain);
    }

    private function _validate_helper($current) {
        if (!$current) {
            return true;
        }
        if ($current->next && $current->value > $current->next->value) {
            return false;
        }
        return $this->_validate_helper($current->next);
    }
}

function main() {
    $mechanism = new ConsensusMechanism();
    for ($i = 0; $i < 10; $i++) {
        $mechanism->append($i);
    }
    echo $mechanism->validate() ? 'true' : 'false';
}

main();

?>