<?php

class Linter extends PhpParser\NodeVisitorAbstract {
    public function visitPhpParser_Node_Stmt_Function($node) {
        if (count($node->stmts) > 10) {
            echo "Function '{$node->name}' exceeds 10 lines.\n";
        }
        return parent::visitPhpParser_Node_Stmt_Function($node);
    }
}

function main() {
    $parser = new PhpParser\ParserFactory();
    $parser = $parser->create(PhpParser\ParserFactory::PREFER_PHP7);
    $lexer = new PhpParser\Lexer\Emulative();

    $code = file_get_contents('php://stdin');
    $stmts = $parser->parse($lexer->tokenize($code));

    $traverser = new PhpParser\NodeTraverser();
    $linter = new Linter();
    $traverser->addVisitor($linter);

    $traverser->traverse($stmts);
}

if (__FILE__ == $_SERVER['argv'][0]) {
    main();
}