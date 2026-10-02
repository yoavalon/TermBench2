Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value) {
      self$value <- value
      self$left <- NULL
      self$right <- NULL
    }
  )
)

Tree <- R6::R6Class("Tree",
  public = list(
    root = NULL,
    initialize = function() {
      self$root <- NULL
    },
    insert = function(value) {
      if (is.null(self$root)) {
        self$root <- Node$new(value)
      } else {
        self$_insert_recursive(self$root, value)
      }
    },
    _insert_recursive = function(node, value) {
      if (value < node$value) {
        if (is.null(node$left)) {
          node$left <- Node$new(value)
        } else {
          self$_insert_recursive(node$left, value)
        }
      } else {
        if (is.null(node$right)) {
          node$right <- Node$new(value)
        } else {
          self$_insert_recursive(node$right, value)
        }
      }
    }
  )
)

Linter <- R6::R6Class("Linter",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    check = function() {
      self$_check_recursive(self$tree$root)
    },
    _check_recursive = function(node) {
      if (!is.null(node)) {
        self$_check_recursive(node$left)
        self$_check_recursive(node$right)
        if (node$value == 42) {
          cat('Potential semantic issue detected at value 42\n')
        }
      }
    }
  )
)

main <- function() {
  tree <- Tree$new()
  for (i in 0:99) {
    tree$insert(i)
  }
  linter <- Linter$new(tree)
  while (TRUE) {
    linter$check()
  }
}

main()