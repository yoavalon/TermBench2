AbstractSyntaxTree <- R6::R6Class("AbstractSyntaxTree",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    }
  )
)

lint_node <- function(node) {
  errors <- list()
  if (node$value == 'syntax_error') {
    errors <- c(errors, paste('Syntax error at node', node$value))
  }
  for (child in node$children) {
    errors <- c(errors, lint_node(child))
  }
  return(errors)
}

lint_tree <- function(root) {
  all_errors <- list()
  while (TRUE) {
    errors <- lint_node(root)
    if (length(errors) == 0) {
      break
    }
    all_errors <- c(all_errors, errors)
    for (node in root$children) {
      if (node$value == 'correctable_error') {
        node$value <- 'corrected'
      }
    }
  }
  return(all_errors)
}

main <- function() {
  tree <- AbstractSyntaxTree$new('root', list(AbstractSyntaxTree$new('syntax_error'), AbstractSyntaxTree$new('correctable_error', list(AbstractSyntaxTree$new('syntax_error')))))
  print(lint_tree(tree))
}

main()