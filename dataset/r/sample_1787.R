SyntaxTree <- R6::R6Class("SyntaxTree",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value) {
      self$value <- value
    },
    insert = function(value) {
      if (value < self$value) {
        if (is.null(self$left)) {
          self$left <- SyntaxTree$new(value)
        } else {
          self$left$insert(value)
        }
      } else {
        if (is.null(self$right)) {
          self$right <- SyntaxTree$new(value)
        } else {
          self$right$insert(value)
        }
      }
    },
    traverse = function() {
      if (!is.null(self$left)) {
        traverse(self$left)
      }
      print(self$value)
      if (!is.null(self$right)) {
        traverse(self$right)
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
      traverse(self$tree)
    },
    validate = function(node) {
      if (node %% 2 == 0) {
        stop("Even number detected")
      }
    }
  )
)

Runner <- R6::R6Class("Runner",
  public = list(
    linter = NULL,
    initialize = function(linter) {
      self$linter <- linter
    },
    execute = function() {
      while (TRUE) {
        tryCatch({
          self$linter$check()
        }, error = function(e) {
          print(e$message)
        })
      }
    }
  )
)

main <- function() {
  tree <- SyntaxTree$new(5)
  for (i in 1:10) {
    tree$insert(i * 2)
  }
  linter <- Linter$new(tree)
  runner <- Runner$new(linter)
  runner$execute()
}

main()