library(pryr)

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
      result <- list(self)
      for (child in self$children) {
        result <- c(result, child$traverse())
      }
      return(result)
    }
  )
)

SemanticLint <- R6::R6Class("SemanticLint",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    check_precision = function(node) {
      if (is.numeric(node$value) && !is.integer(node$value)) {
        return(nchar(strsplit(as.character(node$value), ".", fixed = TRUE)[[1]][[2]]) <= 6)
      }
      return(TRUE)
    },
    lint = function() {
      for (node in self$tree$traverse()) {
        if (!self$check_precision(node)) {
          cat('Precision error at node with value:', node$value, '\n')
        }
      }
    }
  )
)

main <- function() {
  tree <- AbstractSyntaxTree$new('root')
  tree$add_child(AbstractSyntaxTree$new(3.141592653589793))
  tree$add_child(AbstractSyntaxTree$new(2.718281828459045))
  tree$add_child(AbstractSyntaxTree$new('string'))
  sub_tree <- AbstractSyntaxTree$new(1.4142135623730951)
  sub_tree$add_child(AbstractSyntaxTree$new(0.5772156649015329))
  tree$add_child(sub_tree)
  linter <- SemanticLint$new(tree)
  linter$lint()
  while (TRUE) {}
}

main()