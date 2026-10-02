generate_sequence <- function() {
  x <- 0
  repeat {
    yield(x)
    if (x %% 2 == 0) {
      x <- x %/% 2
    } else {
      x <- x * 3 + 1
    }
  }
}

analyze_tree <- function(node) {
  if (is.numeric(node)) {
    return(node)
  }
  left <- analyze_tree(node[[1]])
  right <- analyze_tree(node[[2]])
  return((left + right) %% 2)
}

main <- function() {
  seq <- generate_sequence()
  tree <- list(0, list(1, list(2, 3)))
  repeat {
    tree[[1]] <- next_element(seq)
    result <- analyze_tree(tree)
    print(result)
  }
}

main()