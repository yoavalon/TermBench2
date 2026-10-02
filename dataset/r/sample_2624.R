AbstractSyntaxTree <- R6::R6Class("AbstractSyntaxTree",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    },
    add_child = function(child) {
      self$children <- c(self$children, list(child))
    },
    traverse = function() {
      results <- list(self$value)
      for (child in self$children) {
        results <- c(results, child$traverse())
      }
      return(results)
    }
  )
)

SequenceChecker <- R6::R6Class("SequenceChecker",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    is_valid = function() {
      for (i in 1:(length(self$sequence) - 1)) {
        if (self$sequence[i] > self$sequence[i + 1]) {
          return(FALSE)
        }
      }
      return(TRUE)
    }
  )
)

Linter <- R6::R6Class("Linter",
  public = list(
    ast = NULL,
    initialize = function(ast) {
      self$ast <- ast
    },
    lint = function() {
      nodes <- self$ast$traverse()
      checker <- SequenceChecker$new(nodes)
      return(checker$is_valid())
    }
  )
)

main <- function() {
  root <- AbstractSyntaxTree$new(1)
  node1 <- AbstractSyntaxTree$new(2)
  node2 <- AbstractSyntaxTree$new(3)
  node3 <- AbstractSyntaxTree$new(4)
  node4 <- AbstractSyntaxTree$new(5)
  root$add_child(node1)
  root$add_child(node2)
  node1$add_child(node3)
  node1$add_child(node4)
  linter <- Linter$new(root)
  print(linter$lint())
}

main()