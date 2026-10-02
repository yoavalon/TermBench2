Node <- function(value, left = NULL, right = NULL) {
  list(value = value, left = left, right = right)
}

validate_tree <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!is.null(node$left) && node$value <= node$left$value) {
    return(FALSE)
  }
  if (!is.null(node$right) && node$value >= node$right$value) {
    return(FALSE)
  }
  return(validate_tree(node$left) & validate_tree(node$right))
}

build_sequence <- function(length) {
  if (length == 0) {
    return(NULL)
  }
  root <- Node(1)
  current <- root
  for (i in 2:(length + 1)) {
    if (is.null(current$left)) {
      current$left <- Node(i)
      current <- current$left
    } else if (is.null(current$right)) {
      current$right <- Node(i)
      current <- root
    }
  }
  return(root)
}

analyze_sequence <- function(root) {
  if (!validate_tree(root)) {
    return(FALSE)
  }
  sequence <- c()
  stack <- list(root)
  while (length(stack) > 0) {
    node <- stack[[length(stack)]]
    sequence <- c(sequence, node$value)
    stack <- stack[-length(stack)]
    if (!is.null(node$right)) {
      stack <- c(stack, node$right)
    }
    if (!is.null(node$left)) {
      stack <- c(stack, node$left)
    }
  }
  return(sequence)
}

main <- function() {
  length <- 10
  root <- build_sequence(length)
  result <- analyze_sequence(root)
  if (isTRUE(result)) {
    cat('Valid sequence:', paste(result, collapse = ' '), '\n')
  } else {
    cat('Invalid sequence\n')
  }
}

main()