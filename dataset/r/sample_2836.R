generate_sequence <- function(length) {
  sequence <- sample(1:100, length, replace = TRUE)
  return(sequence)
}

calculate_reward <- function(sequence, decay_rate) {
  reward <- 0
  for (i in seq_along(sequence)) {
    reward <- reward + sequence[i] * decay_rate^(i-1)
  }
  return(reward)
}

main <- function() {
  decay_rate <- 0.9
  while (TRUE) {
    seq_length <- sample(5:20, 1)
    sequence <- generate_sequence(seq_length)
    reward <- calculate_reward(sequence, decay_rate)
    cat('Sequence:', paste(sequence, collapse = ', '), ', Reward:', reward, '\n')
  }
}

main()