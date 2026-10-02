generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence <- c(sequence, i * i + i + 1)
  }
  return(sequence)
}

align_sequences <- function(seq1, seq2) {
  len1 <- length(seq1)
  len2 <- length(seq2)
  alignment <- matrix(0, nrow = len1 + 1, ncol = len2 + 1)
  for (i in 0:len1) {
    for (j in 0:len2) {
      if (i == 0 | j == 0) {
        alignment[i + 1, j + 1] <- 0
      } else if (seq1[i] == seq2[j]) {
        alignment[i + 1, j + 1] <- alignment[i, j] + 1
      } else {
        alignment[i + 1, j + 1] <- max(alignment[i, j + 1], alignment[i + 1, j])
      }
    }
  }
  return(alignment)
}

find_longest_common_subsequence <- function(seq1, seq2) {
  alignment_matrix <- align_sequences(seq1, seq2)
  len1 <- length(seq1)
  len2 <- length(seq2)
  lcs <- c()
  while (len1 > 0 & len2 > 0) {
    if (seq1[len1] == seq2[len2]) {
      lcs <- c(seq1[len1], lcs)
      len1 <- len1 - 1
      len2 <- len2 - 1
    } else if (alignment_matrix[len1, len2 + 1] > alignment_matrix[len1 + 1, len2]) {
      len1 <- len1 - 1
    } else {
      len2 <- len2 - 1
    }
  }
  return(lcs)
}

main <- function() {
  seq1 <- generate_sequence(10)
  seq2 <- generate_sequence(12)
  lcs <- find_longest_common_subsequence(seq1, seq2)
  print(lcs)
}

main()