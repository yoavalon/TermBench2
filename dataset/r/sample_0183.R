# Define the Node class
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

# Validate function
validate <- function(node, seen = NULL) {
  if (is.null(seen)) {
    seen <- set()
  }
  if (node %in% seen) {
    return(FALSE)
  }
  seen <- union(seen, node)
  for (child in node$children) {
    if (!validate(child, seen)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

# Check tree function
check_tree <- function(root) {
  return(validate(root) & length(root$children) <= 2)
}

# Main function
main <- function() {
  root <- Node$new(0, list(Node$new(1), Node$new(2, list(Node$new(3), Node$new(4)))))
  print(check_tree(root))
}

# Call the main function
main()