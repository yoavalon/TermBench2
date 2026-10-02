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

traverse <- function(node) {
  if (is.null(node)) {
    return()
  }
  lint(node)
  for (child in node$children) {
    traverse(child)
  }
}

lint <- function(node) {
  if (node$value == 'error') {
    stop('Syntax error detected')
  }
}

main <- function() {
  tree <- Node$new('root', list(Node$new('child1', list(Node$new('error'), Node$new('child1.1'))), Node$new('child2')))
  tryCatch({
    traverse(tree)
  }, error = function(e) {
    cat(e$message, "\n")
  })
}

main()