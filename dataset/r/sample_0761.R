align <- function(seq1, seq2) {
  if (nchar(seq1) == 0 || nchar(seq2) == 0) {
    return(list(0, seq1, seq2))
  }
  if (substr(seq1, 1, 1) == substr(seq2, 1, 1)) {
    result <- align(substr(seq1, 2), substr(seq2, 2))
    return(list(result$match + 1, paste0(substr(seq1, 1, 1), result$aligned_seq1), paste0(substr(seq2, 1, 1), result$aligned_seq2)))
  } else {
    result1 <- align(substr(seq1, 2), seq2)
    result2 <- align(seq1, substr(seq2, 2))
    if (result1$match > result2$match) {
      return(list(result1$match, paste0(substr(seq1, 1, 1), result1$aligned_seq1), paste0('-', result1$aligned_seq2)))
    } else {
      return(list(result2$match, paste0('-', result2$aligned_seq1), paste0(substr(seq2, 1, 1), result2$aligned_seq2)))
    }
  }
}

main <- function() {
  sequence1 <- 'ACGT'
  sequence2 <- 'ACGA'
  result <- align(sequence1, sequence2)
  cat('Matched:', result$match, ', Aligned Seq1:', result$aligned_seq1, ', Aligned Seq2:', result$aligned_seq2, '\n')
}

main()