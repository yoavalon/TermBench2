library(R6)

Node <- R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    }
  )
)

SyntaxTree <- R6Class("SyntaxTree",
  public = list(
    root = NULL,
    initialize = function(root) {
      self$root <- root
    },
    traverse = function(node) {
      if (is.null(node)) {
        return(c())
      }
      results <- c()
      for (child in node$children) {
        results <- c(results, self$traverse(child))
      }
      results <- c(results, node$value)
      return(results)
    }
  )
)

Linter <- R6Class("Linter",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    lint = function() {
      values <- self$tree$traverse(self$tree$root)
      issues <- c()
      for (value in values) {
        if (is.numeric(value) && !is.integer(value)) {
          issues <- c(issues, value)
        }
      }
      return(issues)
    }
  )
)

create_tree <- function() {
  n1 <- Node$new(1.0)
  n2 <- Node$new(2.5)
  n3 <- Node$new(3.0)
  n4 <- Node$new(4.0)
  n5 <- Node$new(5.5)
  n2$children <- c(n3, n4)
  n1$children <- c(n2, n5)
  return(SyntaxTree$new(n1))
}

main <- function() {
  tree <- create_tree()
  linter <- Linter$new(tree)
  issues <- linter$lint()
  print(paste('Floating point issues:', paste(issues, collapse = ', ')))
}

main()