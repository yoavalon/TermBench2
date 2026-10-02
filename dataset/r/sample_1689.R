mutate_sequence <- function(seq, mutations) {
  for (i in seq_along(mutations)) {
    if (i >= 1 && i <= length(seq)) {
      seq[i] <<- mutations[i]
    }
  }
}

align_sequences <- function(seq1, seq2, mutations) {
  mutate_sequence(seq1, mutations)
  sum(seq1 == seq2)
}

main <- function() {
  seq1 <- c('A', 'T', 'C', 'G', 'A')
  seq2 <- c('A', 'C', 'C', 'G', 'T')
  mutations <- c('C', 'G', 'T', 'A', 'G')
  while (TRUE) {
    score <- align_sequences(seq1, seq2, mutations)
    print(score)
  }
}

main()