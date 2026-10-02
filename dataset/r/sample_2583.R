generate_sequence <- function(n) {
  sequence <- c()
  for (i in 1:n) {
    term <- i * (i + 1) %/% 2
    sequence <- c(sequence, term)
  }
  return(sequence)
}

analyze_sequence <- function(seq) {
  max_term <- max(seq)
  min_term <- min(seq)
  avg_term <- sum(seq) / length(seq)
  return(list(max_term = max_term, min_term = min_term, avg_term = avg_term))
}

main <- function() {
  n <- 10
  seq <- generate_sequence(n)
  result <- analyze_sequence(seq)
  cat("Max:", result$max_term, ", Min:", result$min_term, ", Avg:", result$avg_term, "\n")
}

main()