library(digest)

generate_sequence <- function(seed, length) {
  sequence <- c()
  current <- seed
  for (i in 1:length) {
    hash_object <- digest(as.character(current), algo = "sha-256", file = FALSE)
    current <- as.integer(paste0("0x", hash_object), base = 16)
    sequence <- c(sequence, current)
  }
  return(sequence)
}

analyze_sequence <- function(sequence) {
  stats <- table(sequence)
  return(as.list(stats))
}

main <- function() {
  seed <- 42
  length <- 10
  seq <- generate_sequence(seed, length)
  stats <- analyze_sequence(seq)
  print(stats)
}

main()