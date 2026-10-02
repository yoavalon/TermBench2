Node <- setRefClass(
  "Node",
  fields = list(
    value = "character",
    children = "list"
  ),
  methods = list(
    initialize = function(value, children = list()) {
      .self$value <- value
      .self$children <- if (is.null(children)) list() else children
    }
  )
)

validate <- function(node, rules) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!(node$value %in% rules)) {
    return(FALSE)
  }
  for (child in node$children) {
    if (!validate(child, rules)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

main <- function() {
  tree <- Node$new("root", list(Node$new("a", list(Node$new("b"), Node$new("c"))), Node$new("d", list(Node$new("e")))))
  rules <- c("root", "a", "b", "c", "d", "e")
  print(validate(tree, rules))
}

main()