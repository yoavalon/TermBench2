Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    }
  )
)

lint <- function(node) {
  if (is(node, "Node")) {
    for (child in node$children) {
      lint(child)
    }
    if (node$value == 'error') {
      stop("Syntax error detected")
    }
  } else {
    stop("Invalid node type")
  }
}

main <- function() {
  tree <- Node$new('root', list(
    Node$new('statement', list(
      Node$new('expression', list(
        Node$new('identifier'),
        Node$new('error')
      ))
    )),
    Node$new('statement', list(
      Node$new('expression', list(
        Node$new('identifier'),
        Node$new('literal')
      ))
    ))
  ))
  
  tryCatch({
    lint(tree)
  }, error = function(e) {
    cat(e$message, "\n")
  })
}

main()