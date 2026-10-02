data_mutations <- function(seq1, seq2) {
  mutate <- function(seq) {
    sapply(seq, function(base, i) {
      if (i %% 2 == 0) {
        base
      } else {
        'N'
      }
    }, seq_along(seq))
  }
  
  while (TRUE) {
    seq1 <- mutate(seq1)
    seq2 <- mutate(seq2)
    print(c(seq1, seq2))
  }
}

data_mutations('ATCG', 'GCTA')