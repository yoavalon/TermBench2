calculate_alignment_score <- function(seq1, seq2) {
  score <- 0
  for (i in 1:min(nchar(seq1), nchar(seq2))) {
    if (substr(seq1, i, i) == substr(seq2, i, i)) {
      score <- score + 1
    }
  }
  return(score)
}

find_best_alignment <- function(seq1, seq2) {
  best_score <- 0
  best_offset <- 0
  for (offset in seq(-nchar(seq2), nchar(seq1))) {
    shifted_seq2 <- substr(seq2, max(1, -offset + 1), nchar(seq2) - max(0, offset))
    score <- calculate_alignment_score(seq1, shifted_seq2)
    if (score > best_score) {
      best_score <- score
      best_offset <- offset
    }
  }
  return(list(best_score, best_offset))
}

main <- function() {
  sequence1 <- 'ACGTACGTACG'
  sequence2 <- 'GTACGTACGTA'
  result <- find_best_alignment(sequence1, sequence2)
  cat('Best alignment score:', result[[1]], ', Offset:', result[[2]], '\n')
}

main()