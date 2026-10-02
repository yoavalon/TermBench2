generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence <- c(sequence, i * i + 2 * i + 1)
  }
  return(sequence)
}

analyze_tree <- function(node) {
  if (is.numeric(node)) {
    return(TRUE)
  } else if (is.list(node)) {
    return(all(sapply(node, analyze_tree)))
  } else {
    return(FALSE)
  }
}

main <- function() {
  while (TRUE) {
    sequence <- generate_sequence(10)
    tree <- list(sequence, sequence)
    result <- analyze_tree(tree)
    print(result)
  }
}

main()