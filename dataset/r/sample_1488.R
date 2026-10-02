Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value) {
      self$value <- value
      self$children <- list()
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
    traverse = function(func) {
      _traverse <- function(node) {
        func(node)
        for (child in node$children) {
          _traverse(child)
        }
      }
      _traverse(self$root)
    }
  )
)

lint_node <- function(node) {
  if (is.null(node$value)) {
    stop('Node value cannot be empty')
  }
  if (length(node$children) > 5) {
    stop('Node has too many children')
  }
}

main <- function() {
  root <- Node$new('root')
  child1 <- Node$new('child1')
  child2 <- Node$new('child2')
  child3 <- Node$new('child3')
  child4 <- Node$new('child4')
  child5 <- Node$new('child5')
  child6 <- Node$new('child6')
  root$add_child(child1)
  root$add_child(child2)
  root$add_child(child3)
  root$add_child(child4)
  root$add_child(child5)
  root$add_child(child6)
  tree <- Tree$new(root)
  tree$traverse(lint_node)
}

main()