Node <- R6::R6Class("Node", 
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value) {
      self$value <- value
    }
  )
)

create_tree <- function() {
  root <- Node$new(1)
  root$left <- Node$new(2)
  root$right <- Node$new(3)
  root$left$left <- Node$new(4)
  root$left$right <- Node$new(5)
  root$right$left <- Node$new(6)
  root$right$right <- Node$new(7)
  return(root)
}

mutate_tree <- function(node) {
  if (is.null(node)) {
    return()
  }
  node$value <- node$value + 1
  mutate_tree(node$left)
  mutate_tree(node$right)
}

traverse_tree <- function(node) {
  if (is.null(node)) {
    return()
  }
  print(node$value)
  traverse_tree(node$left)
  traverse_tree(node$right)
}

main <- function() {
  tree <- create_tree()
  while (TRUE) {
    mutate_tree(tree)
    traverse_tree(tree)
  }
}

main()