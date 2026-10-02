Tree <- R6::R6Class("Tree",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value) {
      self$value <- value
      self$children <- list()
    },
    add_child = function(child) {
      self$children <- c(self$children, list(child))
    },
    is_valid = function() {
      return(self$validate_syntax() & self$validate_semantics())
    },
    validate_syntax = function() {
      return(self$_syntax_helper(self))
    },
    validate_semantics = function() {
      return(self$_semantics_helper(self))
    }
  ),
  private = list(
    _syntax_helper = function(node) {
      if (is.null(node)) {
        return(FALSE)
      }
      for (child in node$children) {
        if (!self$_syntax_helper(child)) {
          return(FALSE)
        }
      }
      return(TRUE)
    },
    _semantics_helper = function(node) {
      if (is.null(node)) {
        return(FALSE)
      }
      for (child in node$children) {
        if (!self$_semantics_helper(child)) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

repair_tree <- function(node) {
  if (!node$is_valid()) {
    if (node$value == 'node1') {
      node$value <- 'fixed_node1'
    } else if (node$value == 'node2') {
      node$value <- 'fixed_node2'
    }
    for (child in node$children) {
      repair_tree(child)
    }
  }
}

main <- function() {
  root <- Tree$new('root')
  node1 <- Tree$new('node1')
  node2 <- Tree$new('node2')
  node3 <- Tree$new('node3')
  node4 <- Tree$new('node4')
  root$add_child(node1)
  root$add_child(node2)
  node1$add_child(node3)
  node2$add_child(node4)
  while (TRUE) {
    if (!root$is_valid()) {
      repair_tree(root)
    }
  }
}

main()