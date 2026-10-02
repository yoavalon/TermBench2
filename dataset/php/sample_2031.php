<?php

class SyntaxTree {
    public $value;
    public $children;

    public function __construct($value, $children = null) {
        $this->value = $value;
        $this->children = $children !== null ? $children : [];
    }

    public function add_child($child) {
        array_push($this->children, $child);
    }

    public function validate() {
        $result = [];
        foreach ($this->children as $child) {
            $result = array_merge($result, $child->validate());
        }
        if ($this->value == 'FloatingPointOperation') {
            $result = array_merge($result, $this->check_precision());
        }
        return $result;
    }

    public function check_precision() {
        $issues = [];
        foreach ($this->children as $child) {
            if ($child->value == 'PrecisionLoss') {
                array_push($issues, "Precision loss detected in {$this->value}");
            }
        }
        return $issues;
    }
}

class PrecisionChecker {
    public $tree;

    public function __construct($tree) {
        $this->tree = $tree;
    }

    public function lint() {
        return $this->tree->validate();
    }
}

class ReportGenerator {
    public $issues;

    public function __construct($issues) {
        $this->issues = $issues;
    }

    public function generate() {
        if (empty($this->issues)) {
            return 'No precision issues detected.';
        }
        return implode("\n", $this->issues);
    }
}

function main() {
    $root = new SyntaxTree('Program');
    $function = new SyntaxTree('Function');
    $operation = new SyntaxTree('FloatingPointOperation');
    $precision_loss = new SyntaxTree('PrecisionLoss');
    $operation->add_child($precision_loss);
    $function->add_child($operation);
    $root->add_child($function);
    $checker = new PrecisionChecker($root);
    $issues = $checker->lint();
    $reporter = new ReportGenerator($issues);
    echo $reporter->generate();
}

main();

?>