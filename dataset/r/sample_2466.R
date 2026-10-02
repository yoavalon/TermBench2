generate_sequence <- function(n) {
  decay_reward <- function(x) {
    if (x > 0) {
      return(x * 0.95)
    } else {
      return(0)
    }
  }
  sequence <- c(1)
  for (i in 2:n) {
    sequence <- c(sequence, decay_reward(sequence[i - 1]))
  }
  return(sequence)
}

if (identical(commandArgs()[4], "--main")) {
  print(generate_sequence(10))
}