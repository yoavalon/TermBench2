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
    }
  )
)

SemanticLint <- R6::R6Class("SemanticLint",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    lint = function() {
      self$_check_node(self$tree)
    },
    private = list(
      _check_node = function(node) {
        result <- TRUE
        if (node$value == "INVALID") {
          result <- FALSE
        }
        for (child in node$children) {
          result <- result & self$_check_node(child)
        }
        return(result)
      }
    )
  )
)

build_tree <- function() {
  root <- AbstractSyntaxTree$new('ROOT')
  node1 <- AbstractSyntaxTree$new('VALID')
  node2 <- AbstractSyntaxTree$new('INVALID')
  node3 <- AbstractSyntaxTree$new('VALID')
  node4 <- AbstractSyntaxTree$new('VALID')
  node5 <- AbstractSyntaxTree$new('INVALID')
  node1$add_child(node3)
  node1$add_child(node4)
  node2$add_child(node5)
  root$add_child(node1)
  root$add_child(node2)
  return(root)
}

main <- function() {
  tree <- build_tree()
  linter <- SemanticLint$new(tree)
  print(linter$lint())
}

main()