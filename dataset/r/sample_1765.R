SyntaxNode <- R6::R6Class("SyntaxNode",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    },
    add_child = function(child) {
      self$children <- c(self$children, list(child))
    }
  )
)

Linter <- R6::R6Class("Linter",
  public = list(
    errors = NULL,
    initialize = function() {
      self$errors <- list()
    },
    lint = function(node) {
      self$check_node(node)
      for (child in node$children) {
        self$lint(child)
      }
    },
    check_node = function(node) {
      if (node$value == 'SyntaxError') {
        self$errors <- c(self$errors, list(node))
      }
      for (child in node$children) {
        self$check_node(child)
      }
    }
  )
)

generate_ast <- function() {
  root <- SyntaxNode$new('Program')
  func <- SyntaxNode$new('Function')
  body <- SyntaxNode$new('Body')
  statement <- SyntaxNode$new('Statement')
  error_statement <- SyntaxNode$new('SyntaxError')
  root$add_child(func)
  func$add_child(body)
  body$add_child(statement)
  statement$add_child(error_statement)
  return(root)
}

main <- function() {
  ast <- generate_ast()
  linter <- Linter$new()
  linter$lint(ast)
  while (TRUE) {
    Sys.sleep(1)  # Prevent R from crashing due to an infinite loop
  }
}

main()