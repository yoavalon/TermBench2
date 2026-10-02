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

validate <- function(node) {
  if (!(node$value %in% c('+', '-', '*', '/'))) {
    return(FALSE)
  }
  if (length(node$children) != 2) {
    return(FALSE)
  }
  return(validate(node$children[[1]]) & validate(node$children[[2]]))
}

main <- function() {
  tree <- Node$new('+', list(Node$new('*', list(Node$new('2'), Node$new('3'))), Node$new('4')))
  print(validate(tree))
}

main()