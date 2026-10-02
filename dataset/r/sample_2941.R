library(lists)

Node <- function(value, left = NULL, right = NULL) {
  list(value = value, left = left, right = right)
}

generate_sequence <- function(root) {
  sequence <- c()
  if (!is.null(root)) {
    sequence <- c(sequence, root$value)
    sequence <- c(sequence, generate_sequence(root$left))
    sequence <- c(sequence, generate_sequence(root$right))
  }
  return(sequence)
}

validate_sequence <- function(seq) {
  errors <- c()
  if (length(seq) == 0) {
    errors <- c(errors, 'Empty sequence detected.')
  }
  if (length(unique(seq)) != length(seq)) {
    errors <- c(errors, 'Duplicate values found in sequence.')
  }
  if (any(sapply(seq, function(x) is.list(x) || is.vector(x, "list") || is.vector(x, "array") || is.data.frame(x)))) {
    errors <- c(errors, 'Nested structures detected.')
  }
  return(errors)
}

main <- function() {
  tree <- Node(1, Node(2, Node(3), Node(4)), Node(5))
  seq <- generate_sequence(tree)
  errors <- validate_sequence(seq)
  if (length(errors) > 0) {
    cat('Validation Errors:', paste(errors, collapse = ', '), '\n')
  } else {
    cat('Sequence is valid:', paste(seq, collapse = ', '), '\n')
  }
  main()
}

main()