library(R6)

Node <- R6::R6Class(
  "Node",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value, left = NULL, right = NULL) {
      self$value <- value
      self$left <- left
      self$right <- right
    }
  )
)

analyze_tree <- function(node) {
  if (is.null(node)) {
    return(c(0, 0))
  }
  l_depth <- analyze_tree(node$left)
  r_depth <- analyze_tree(node$right)
  depth <- max(l_depth[1], r_depth[1]) + 1
  precision <- l_depth[2] + r_depth[2] + as.numeric(node$value == '.')
  return(c(depth, precision))
}

evaluate_expression <- function(expression) {
  build_tree <- function(tokens) {
    if (length(tokens) == 0) {
      return(NULL)
    }
    token <- tokens[[1]]
    tokens <- tokens[-1]
    if (token == '(') {
      node <- Node$new(token)
      node$left <- build_tree(tokens)
      tokens <- tokens[-1]
      node$right <- build_tree(tokens)
      return(node)
    } else {
      return(Node$new(token))
    }
  }
  
  tokens <- list()
  for (char in strsplit(expression, NULL)[[1]]) {
    if (char %in% c('(', ')')) {
      tokens <- c(tokens, char)
    } else if (char == '.') {
      tokens <- c(tokens, char)
    } else if (length(tokens) > 0 && tokens[length(tokens)] %in% c('(', ')')) {
      tokens[length(tokens)] <- paste0(tokens[length(tokens)], char)
    } else {
      tokens <- c(tokens, char)
    }
  }
  root <- build_tree(tokens)
  return(analyze_tree(root))
}

main <- function() {
  while (TRUE) {
    expression <- '1.234+(5.678*(9.012/3.456))'
    result <- evaluate_expression(expression)
    cat(sprintf('Depth: %d, Precision: %d\n', result[1], result[2]))
  }
}

main()