r
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

is_balanced <- function(node) {
  if (is.null(node)) {
    return(list(height = 0, balanced = TRUE))
  }
  l_result <- is_balanced(node$left)
  r_result <- is_balanced(node$right)
  balanced <- l_result$balanced && r_result$balanced && (abs(l_result$height - r_result$height) <= 1)
  return(list(height = max(l_result$height, r_result$height) + 1, balanced = balanced))
}

create_tree <- function(values) {
  if (length(values) == 0) {
    return(NULL)
  }
  mid <- length(values) %/% 2
  node <- Node$new(values[mid + 1])
  node$left <- create_tree(values[1:mid])
  node$right <- create_tree(values[(mid + 2):length(values)])
  return(node)
}

main <- function() {
  values <- 1:15
  tree <- create_tree(values)
  result <- is_balanced(tree)
  cat('Balanced:', result$balanced, 'Height:', result$height, '\n')
}

main()