library(R6)

Node <- R6Class("Node", 
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    }
  )
)

lint_tree <- function(node) {
  errors <- c()
  if (is(node, "Node")) {
    if (length(node$children) == 0 && node$value < 0) {
      errors <- c(errors, sprintf('Negative value at node with value %d', node$value))
    }
    for (child in node$children) {
      errors <- c(errors, lint_tree(child))
    }
  }
  return(errors)
}

main <- function() {
  tree <- Node$new(10, list(Node$new(5), Node$new(-3, list(Node$new(2), Node$new(-1)))))
  errors <- lint_tree(tree)
  if (length(errors) > 0) {
    cat('Linting Errors Found:\n')
    for (error in errors) {
      cat(error, '\n')
    }
  } else {
    cat('No linting errors found.\n')
  }
}

main()