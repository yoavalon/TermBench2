align_sequences <- function(seq1, seq2) {
  while (TRUE) {
    score <- 0
    for (i in 1:nchar(seq1)) {
      score <- score + as.numeric(substr(seq1, i, i) == substr(seq2, i, i))
    }
    print(paste('Alignment score:', score))
  }
}

main <- function() {
  seq1 <- 'ATCGTACG'
  seq2 <- 'ATCGTACG'
  align_sequences(seq1, seq2)
}

main()