library(pryr)

Node <- R6::R6Class("Node", 
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- if (!is.null(children)) children else list()
    }
  )
)

AbstractSyntaxTree <- R6::R6Class("AbstractSyntaxTree", 
  public = list(
    root = NULL,
    initialize = function(root) {
      self$root <- root
    },
    traverse = function() {
      result <- list()
      self$_traverse(self$root, result)
      return(result)
    }
  ),
  private = list(
    _traverse = function(node, result) {
      if (!is.null(node)) {
        result[[length(result) + 1]] <- node$value
        for (child in node$children) {
          self$_traverse(child, result)
        }
      }
    }
  )
)

SemanticLint <- R6::R6Class("SemanticLint", 
  public = list(
    ast = NULL,
    initialize = function(ast) {
      self$ast <- ast
    },
    analyze = function() {
      issues <- list()
      for (node in self$ast$traverse()) {
        if (self$_has_issue(node)) {
          issues[[length(issues) + 1]] <- node$value
        }
      }
      return(issues)
    }
  ),
  private = list(
    _has_issue = function(node) {
      return(node$value == 'invalid')
    }
  )
)

main <- function() {
  root <- Node$new('root', list(Node$new('valid'), Node$new('invalid', list(Node$new('valid'), Node$new('invalid')))))
  ast <- AbstractSyntaxTree$new(root)
  linter <- SemanticLint$new(ast)
  issues <- linter$analyze()
  cat('Issues found:', paste(issues, collapse = ', '), '\n')
}

if (isTRUE(identical(commandArgs(trailingOnly = TRUE), character(0)))) {
  main()
}