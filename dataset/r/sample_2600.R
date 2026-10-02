generate_sequence <- function(n) {
  sequence <- c()
  for (i in 1:n) {
    sequence <- c(sequence, i * (i + 1) %/% 2)
  }
  return(sequence)
}

optimize_inventory <- function(seq, target) {
  for (i in 1:length(seq)) {
    if (seq[i] >= target) {
      return(list(index = i - 1, value = seq[i]))
    }
  }
  return(list(index = NULL, value = NULL))
}

main <- function() {
  n <- 10
  target <- 20
  seq <- generate_sequence(n)
  result <- optimize_inventory(seq, target)
  if (!is.null(result$index)) {
    cat('Optimal index:', result$index, ', Value:', result$value, '\n')
  } else {
    cat('Target not met.\n')
  }
}

main()