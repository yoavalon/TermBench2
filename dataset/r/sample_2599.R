library(digest)

generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    hash_value <- digest(as.character(i), algo = "sha-256", file = NULL)
    sequence <- c(sequence, as.integer(strtoi(hash_value, base = 16)) %% 1000)
  }
  return(sequence)
}

analyze_sequence <- function(seq) {
  stats <- list(min = min(seq), max = max(seq), avg = mean(seq))
  return(stats)
}

main <- function() {
  seq <- generate_sequence(100)
  stats <- analyze_sequence(seq)
  print(stats)
}

main()