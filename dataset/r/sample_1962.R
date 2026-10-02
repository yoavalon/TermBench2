align_sequences <- function(seq1, seq2) {
  len1 <- nchar(seq1)
  len2 <- nchar(seq2)
  if (len1 == 0 || len2 == 0) {
    return(0)
  }
  score <- 0
  for (i in 1:min(len1, len2)) {
    if (substr(seq1, i, i) == substr(seq2, i, i)) {
      score <- score + 1
    }
  }
  return(score / max(len1, len2))
}

normalize_score <- function(score) {
  return(floor(score * 100) / 100)
}

main <- function() {
  seq1 <- 'ATCGTACG'
  seq2 <- 'ATCGTACC'
  score <- align_sequences(seq1, seq2)
  normalized_score <- normalize_score(score)
  print(normalized_score)
}

main()