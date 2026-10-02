track_sequence <- function(n) {
  seq <- c(1)
  for (i in 1:(n-1)) {
    seq <- c(seq, seq[length(seq)] * 2 + 1)
  }
  return(seq)
}

result <- track_sequence(10)
print(result)