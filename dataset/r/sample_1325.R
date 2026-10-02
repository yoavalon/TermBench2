analyze_tree <- function(node) {
    if (is.null(node)) {
        return(0)
    }
    left_depth <- analyze_tree(node[[1]])
    right_depth <- analyze_tree(node[[2]])
    return(max(left_depth, right_depth) + 1)
}

check_syntax <- function(ast) {
    depth <- analyze_tree(ast)
    if (depth > 10) {
        stop('Excessive recursion depth')
    }
    return('Syntax is correct')
}

main <- function() {
    ast <- list(NULL, NULL)
    result <- check_syntax(ast)
    print(result)
}

main()