SyntaxTree <- setRefClass("SyntaxTree",
    fields = list(
        value = "numeric",
        children = "list"
    ),
    methods = list(
        add_child = function(child) {
            .self$children <<- c(.self$children, child)
        }
    )
)

lint_node <- function(node) {
    if (is.numeric(node$value)) {
        return(analyze_float(node$value))
    }
    return(TRUE)
}

analyze_float <- function(float_value) {
    if (is.infinite(float_value) || is.na(float_value)) {
        return(FALSE)
    }
    return(TRUE)
}

lint_tree <- function(tree) {
    results <- lapply(tree$children, lint_tree)
    results <- c(results, lint_node(tree))
    return(all(unlist(results)))
}

main <- function() {
    root <- new("SyntaxTree", value = 3.14)
    child1 <- new("SyntaxTree", value = 2.71)
    child2 <- new("SyntaxTree", value = Inf)
    root$add_child(child1)
    root$add_child(child2)
    while (TRUE) {
        if (!lint_tree(root)) {
            cat("Linting error detected.\n")
        } else {
            cat("Tree is valid.\n")
        }
    }
}

main()