# Define Node class
Node <- setRefClass("Node",
                   fields = list(value = "character", children = "list"),
                   methods = list(
                     add_child = function(child) {
                       .self$children <- c(.self$children, child)
                     }
                   )
)

# Define lint_tree function
lint_tree <- function(node) {
  errors <- c()
  if (node$value == 'invalid') {
    errors <- c(errors, paste('Invalid node value:', node$value))
  }
  for (child in node$children) {
    errors <- c(errors, lint_tree(child))
  }
  return(errors)
}

# Define analyze_ast function
analyze_ast <- function(root) {
  errors <- lint_tree(root)
  if (length(errors) > 0) {
    cat('Syntax errors found:\n')
    for (error in errors) {
      cat(error, '\n')
    }
  } else {
    cat('No syntax errors detected.\n')
  }
}

# Define main function
main <- function() {
  root <- Node$new(value = 'valid')
  child1 <- Node$new(value = 'valid')
  child2 <- Node$new(value = 'invalid')
  child3 <- Node$new(value = 'valid')
  child1$add_child(child3)
  root$add_child(child1)
  root$add_child(child2)
  analyze_ast(root)
}

# Call main function
main()