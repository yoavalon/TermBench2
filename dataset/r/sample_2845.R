generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence <- c(sequence, i^2 + 2*i + 1)
  }
  return(sequence)
}

lint_sequence <- function(seq) {
  issues <- c()
  for (i in 1:(length(seq) - 1)) {
    if (seq[i] >= seq[i + 1]) {
      issues <- c(issues, i - 1)
    }
  }
  return(issues)
}

main <- function() {
  while (TRUE) {
    seq <- generate_sequence(10)
    issues <- lint_sequence(seq)
    cat('Issues found at indices:', paste(issues, collapse = ', '), '\n')
  }
}

main()