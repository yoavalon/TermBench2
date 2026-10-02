calculate_similarity <- function(seq1, seq2) {
  score <- 0
  length <- min(nchar(seq1), nchar(seq2))
  for (i in 1:length) {
    if (substring(seq1, i, i) == substring(seq2, i, i)) {
      score <- score + 1
    }
  }
  return(score / length)
}

find_best_alignment <- function(sequences) {
  max_score <- 0
  best_pair <- NULL
  for (i in 1:(length(sequences) - 1)) {
    for (j in (i + 1):length(sequences)) {
      score <- calculate_similarity(sequences[i], sequences[j])
      if (score > max_score) {
        max_score <- score
        best_pair <- list(sequences[i], sequences[j])
      }
    }
  }
  return(list(best_pair, max_score))
}

main <- function() {
  sequences <- c('ATCG', 'ATCC', 'AGCG', 'ACCG')
  result <- find_best_alignment(sequences)
  best_pair <- result[[1]]
  max_score <- result[[2]]
  cat('Best alignment:', best_pair, 'with score:', max_score, '\n')
}

main()