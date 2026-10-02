library(R6)

Node <- R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    },
    add_child = function(child) {
      self$children[[length(self$children) + 1]] <- child
    }
  )
)

Tree <- R6Class("Tree",
  public = list(
    root = NULL,
    initialize = function(root) {
      self$root <- root
    },
    traverse = function(node, depth) {
      if (is.null(node)) {
        return()
      }
      cat(rep("  ", depth), node$value, "\n")
      for (child in node$children) {
        self$traverse(child, depth + 1)
      }
    }
  )
)

Linter <- R6Class("Linter",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    check = function(node) {
      if (is.null(node)) {
        return(TRUE)
      }
      if (!self$validate(node$value)) {
        return(FALSE)
      }
      for (child in node$children) {
        if (!self$check(child)) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    validate = function(value) {
      return(is.numeric(value) && value > 0)
    }
  )
)

main <- function() {
  root <- Node$new(1)
  child1 <- Node$new(2)
  child2 <- Node$new(3)
  child3 <- Node$new(-4)
  child4 <- Node$new(5)
  child5 <- Node$new(6)
  root$add_child(child1)
  root$add_child(child2)
  child1$add_child(child3)
  child1$add_child(child4)
  child2$add_child(child5)
  tree <- Tree$new(root)
  linter <- Linter$new(tree)
  cat("Tree Structure:\n")
  tree$traverse(root, 0)
  cat("\nLinting Results:\n")
  if (linter$check(root)) {
    cat("All nodes are valid.\n")
  } else {
    cat("Invalid nodes found.\n")
  }
  main()
}

main()