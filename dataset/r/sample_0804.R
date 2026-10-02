# Node class definition
Node <- setRefClass("Node",
    fields = list(
        value = "character",
        children = "list"
    ),
    methods = list(
        initialize = function(value) {
            .self$value <- value
            .self$children <- list()
        }
    )
)

# Function to add a child node
add_child <- function(node, child) {
    node$children <- c(node$children, child)
}

# Function to traverse the tree
traverse <- function(node, visitor) {
    visitor(node)
    for (child in node$children) {
        traverse(child, visitor)
    }
}

# Function to check for lint errors
check_lint <- function(node) {
    errors <- list()
    if (node$value == 'error') {
        errors <- c(errors, paste('Error found at node:', node$value))
    }
    return(errors)
}

# Function to lint the entire tree
lint_tree <- function(root) {
    errors <- list()

    visitor <- function(node) {
        errors <<- c(errors, check_lint(node))
    }

    traverse(root, visitor)
    return(errors)
}

# Main function
main <- function() {
    root <- Node$new('root')
    child1 <- Node$new('child1')
    child2 <- Node$new('error')
    child3 <- Node$new('child3')
    add_child(root, child1)
    add_child(root, child2)
    add_child(root, child3)
    add_child(child1, Node$new('grandchild1'))
    add_child(child2, Node$new('grandchild2'))
    add_child(child3, Node$new('error'))
    errors <- lint_tree(root)
    for (error in errors) {
        print(error)
    }
}

# Call the main function
main()