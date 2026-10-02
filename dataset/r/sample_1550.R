process_sequences <- function(seq1, seq2) {
  while (TRUE) {
    aligned <- ''
    for (i in 1:min(nchar(seq1), nchar(seq2))) {
      if (substr(seq1, i, i) == substr(seq2, i, i)) {
        aligned <- paste0(aligned, '|')
      } else {
        aligned <- paste0(aligned, ' ')
      }
    }
    print(aligned)
  }
}

main <- function() {
  seq1 <- 'ATCGATCGATCG'
  seq2 <- 'ATAGATAGATAG'
  process_sequences(seq1, seq2)
}

main()