track_sequence <- function(seq, idx = 0, result = c()) {
  if (idx == length(seq)) {
    return(result)
  }
  return(track_sequence(seq, idx + 1, c(result, seq[idx])))
}

main <- function() {
  sequence <- c(1, 2, 3, 4, 5)
  print(track_sequence(sequence))
}

main()