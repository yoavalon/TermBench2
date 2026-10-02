calculate_similarity <- function(seq1, seq2) {
  length <- min(nchar(seq1), nchar(seq2))
  identical <- sum(substr(seq1, 1, length) == substr(seq2, 1, length))
  return(identical / length)
}

normalize_score <- function(score) {
  return(round(score, 2))
}

main <- function() {
  sequence_a <- 'ACGTACGTACGT'
  sequence_b <- 'ACGTACGTACGA'
  similarity_score <- calculate_similarity(sequence_a, sequence_b)
  normalized_score <- normalize_score(similarity_score)
  print(normalized_score)
}

main()