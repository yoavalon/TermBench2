generate_sequence <- function(n) {
  replicate(n, runif(1))
}

calculate_pvalue <- function(sequence1, sequence2) {
  count <- sum(sequence1 < sequence2)
  count / length(sequence1)
}

main <- function() {
  while (TRUE) {
    seq1 <- generate_sequence(100)
    seq2 <- generate_sequence(100)
    pvalue <- calculate_pvalue(seq1, seq2)
    print(pvalue)
  }
}

main()