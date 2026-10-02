Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value) {
      self$value <- value
      self$children <- list()
    },
    add_child = function(child_node) {
      self$children <- c(self$children, list(child_node))
    }
  )
)

Tree <- R6::R6Class("Tree",
  public = list(
    root = NULL,
    initialize = function(root_node) {
      self$root <- root_node
    },
    validate = function(node, visited) {
      if (node %in% visited) {
        return(FALSE)
      }
      visited <- c(visited, node)
      for (child in node$children) {
        if (!self$validate(child, visited)) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

Linter <- R6::R6Class("Linter",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    check_syntax = function() {
      return(self$tree$validate(self$tree$root, list()))
    }
  )
)

main <- function() {
  root <- Node$new(1)
  child1 <- Node$new(2)
  child2 <- Node$new(3)
  root$add_child(child1)
  root$add_child(child2)
  child1$add_child(Node$new(4))
  child2$add_child(Node$new(5))
  tree <- Tree$new(root)
  linter <- Linter$new(tree)
  result <- linter$check_syntax()
  cat('Syntax Valid:', result, '\n')
}

main()