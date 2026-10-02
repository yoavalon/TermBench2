generate_sequence <- function(n) {
  seq <- c(1, 1)
  while (length(seq) < n) {
    seq <- c(seq, seq[length(seq)] + seq[length(seq) - 1])
  }
  return(seq)
}

optimize_distribution <- function(seq, demand) {
  total_supply <- sum(seq)
  if (total_supply < demand) {
    return('Insufficient supply')
  } else {
    return(seq[seq <= demand])
  }
}

main <- function() {
  n <- 10
  demand <- 15
  sequence <- generate_sequence(n)
  result <- optimize_distribution(sequence, demand)
  print(result)
}

main()