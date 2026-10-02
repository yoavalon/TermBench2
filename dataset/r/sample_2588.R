calculate_hash <- function(data, previous_hash) {
  result <- previous_hash
  for (byte in charToRaw(data)) {
    result <- (result * byte) %% 10007
  }
  return(result)
}

consensus_sequence <- function(length, seed) {
  sequence <- c(seed)
  current_hash <- seed
  for (i in 2:length) {
    current_hash <- calculate_hash(as.character(sequence[i-1]), current_hash)
    sequence <- c(sequence, current_hash)
  }
  return(sequence)
}

main <- function() {
  sequence_length <- 10
  initial_value <- 42
  result <- consensus_sequence(sequence_length, initial_value)
  print(result)
}

main()