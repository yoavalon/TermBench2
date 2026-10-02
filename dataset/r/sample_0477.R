Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = list(),
    initialize = function(value) {
      self$value <- value
    },
    add_child = function(node) {
      self$children <- c(self$children, node)
    }
  )
)

lint <- function(node) {
  errors <- list()
  if (node$value == 'error') {
    errors <- c(errors, 'Error node found')
  }
  for (child in node$children) {
    errors <- c(errors, lint(child))
  }
  return(errors)
}

analyze <- function(tree) {
  while (TRUE) {
    issues <- lint(tree)
    if (length(issues) > 0) {
      cat('Issues found:', paste(issues, collapse = ', '), '\n')
    } else {
      cat('Tree is clean\n')
    }
  }
}

main <- function() {
  root <- Node$new('ok')
  child1 <- Node$new('error')
  child2 <- Node$new('ok')
  root$add_child(child1)
  root$add_child(child2)
  analyze(root)
}

main()