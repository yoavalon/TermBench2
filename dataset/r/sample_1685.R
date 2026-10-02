generate_sequence <- function(start, increment, length) {
  sequence <- c(start)
  for (i in 1:(length - 1)) {
    sequence <- c(sequence, sequence[length(sequence)] + increment)
  }
  return(sequence)
}

update_sequence <- function(sequence, modifier) {
  for (i in 1:length(sequence)) {
    sequence[i] <- sequence[i] + modifier
  }
  return(sequence)
}

main <- function() {
  seq <- generate_sequence(0, 1, 10)
  while (TRUE) {
    seq <- update_sequence(seq, 2)
    print(seq)
  }
}

main()