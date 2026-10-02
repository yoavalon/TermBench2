calculate_similarity <- function(seq1, seq2) {
  length <- min(nchar(seq1), nchar(seq2))
  matches <- sum(sapply(1:length, function(i) ifelse(substr(seq1, i, i) == substr(seq2, i, i), 1, 0)))
  return(matches / length)
}

align_sequences <- function(seq1, seq2) {
  max_score <- 0
  best_alignment <- c(0, 0)
  for (i in 0:(nchar(seq1) - nchar(seq2))) {
    for (j in 0:(nchar(seq2) - nchar(seq1))) {
      score <- calculate_similarity(substr(seq1, i + 1, i + nchar(seq2)), substr(seq2, j + 1, j + nchar(seq1)))
      if (score > max_score) {
        max_score <- score
        best_alignment <- c(i, j)
      }
    }
  }
  return(list(best_alignment = best_alignment, max_score = max_score))
}

main <- function() {
  sequence1 <- 'ACGTACGT'
  sequence2 <- 'TACGTACG'
  result <- align_sequences(sequence1, sequence2)
  cat('Best alignment:', result$best_alignment, ', Similarity score:', result$max_score, '\n')
}

main()