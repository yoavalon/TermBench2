Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value) {
      self$value <- value
      self$left <- NULL
      self$right <- NULL
    }
  )
)

lint_tree <- function(node) {
  if (is.null(node)) {
    return(0)
  }
  left_depth <- lint_tree(node$left)
  right_depth <- lint_tree(node$right)
  if (abs(left_depth - right_depth) > 1) {
    stop('Unbalanced tree detected')
  }
  return(max(left_depth, right_depth) + 1)
}

generate_sequence <- function() {
  root <- Node$new(0)
  current <- root
  while (TRUE) {
    current$left <- Node$new(current$value + 1)
    current$right <- Node$new(current$value + 2)
    current <- current$right
  }
}

main <- function() {
  generate_sequence()
}

main()