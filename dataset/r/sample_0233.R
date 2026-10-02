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
    get_children = function() {
      return(self$children)
    }
  )
)

SemanticLint <- R6::R6Class("SemanticLint",
  public = list(
    ast = NULL,
    errors = NULL,
    initialize = function(ast) {
      self$ast <- ast
      self$errors <- list()
    },
    check = function() {
      self$_traverse(self$ast)
    },
    _traverse = function(node) {
      if (is.null(node)) {
        return()
      }
      self$_analyze_node(node)
      for (child in node$get_children()) {
        self$_traverse(child)
      }
    },
    _analyze_node = function(node) {
      if (!is.character(node$value)) {
        self$errors <- c(self$errors, paste('Invalid node value:', node$value))
      }
      if (length(node$get_children()) > 2) {
        self$errors <- c(self$errors, paste('Too many children at node:', node$value))
      }
    }
  )
)

main <- function() {
  root <- AbstractSyntaxTree$new('root')
  child1 <- AbstractSyntaxTree$new('child1')
  child2 <- AbstractSyntaxTree$new('child2')
  child3 <- AbstractSyntaxTree$new('child3')
  root$add_child(child1)
  root$add_child(child2)
  child1$add_child(child3)
  lint <- SemanticLint$new(root)
  lint$check()
  if (length(lint$errors) > 0) {
    print('Semantic linting errors found:')
    for (error in lint$errors) {
      print(error)
    }
  } else {
    print('No semantic linting errors found.')
  }
}

main()