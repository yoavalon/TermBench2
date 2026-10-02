Node <- R6::R6Class("Node",
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

Tree <- R6::R6Class("Tree",
  public = list(
    root = NULL,
    initialize = function(root) {
      self$root <- root
    },
    traverse = function() {
      result <- list()
      self$_traverse_helper(self$root, result)
      return(result)
    },
    _traverse_helper = function(node, accumulator) {
      if (!is.null(node)) {
        accumulator[[length(accumulator) + 1]] <- node$value
        for (child in node$children) {
          self$_traverse_helper(child, accumulator)
        }
      }
    }
  )
)

SemanticLint <- R6::R6Class("SemanticLint",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    check = function() {
      issues <- list()
      self$_check_helper(self$tree$root, issues)
      return(issues)
    },
    _check_helper = function(node, issues) {
      if (!is.null(node)) {
        if (self$_is_floating_point(node$value)) {
          if (!self$_has_high_precision(node$value)) {
            issues[[length(issues) + 1]] <- paste0('Low precision for ', node$value)
          }
        }
        for (child in node$children) {
          self$_check_helper(child, issues)
        }
      }
    },
    _is_floating_point = function(value) {
      tryCatch({
        as.numeric(value)
        TRUE
      }, error = function(e) {
        FALSE
      })
    },
    _has_high_precision = function(value) {
      abs(as.numeric(value) - round(as.numeric(value), 10)) < 1e-09
    }
  )
)

main <- function() {
  root <- Node$new('1.0')
  child1 <- Node$new('0.1')
  child2 <- Node$new('0.0000000001')
  root$add_child(child1)
  root$add_child(child2)
  tree <- Tree$new(root)
  lint <- SemanticLint$new(tree)
  print(lint$check())
}

main()