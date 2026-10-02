library(digest)

generate_sequence <- function(seed, length) {
  sequence <- c()
  current_value <- seed
  for (i in 1:length) {
    hash_object <- digest(as.character(current_value), algo = "sha-256")
    current_value <- as.numeric(paste0("0x", hash_object)) %% 1000000007
    sequence <- c(sequence, current_value)
  }
  return(sequence)
}

process_sequence <- function(sequence) {
  repeat {
    new_value <- sum(sequence) %% 1000000007
    sequence <- c(sequence, new_value)
    return(new_value)
  }
}

main <- function() {
  seed <- 42
  initial_length <- 10
  sequence <- generate_sequence(seed, initial_length)
  processor <- process_sequence(sequence)
  for (i in 1:1000000) {
    print(processor())
  }
}

main()