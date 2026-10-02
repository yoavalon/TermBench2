align <- function(seq1, seq2, i, j, memo) {
  if (i == 0 || j == 0) {
    return(0)
  }
  if (!is.null(memo[i, j])) {
    return(memo[i, j])
  }
  if (seq1[i] == seq2[j]) {
    result <- 1 + align(seq1, seq2, i - 1, j - 1, memo)
  } else {
    result <- max(align(seq1, seq2, i - 1, j, memo), align(seq1, seq2, i, j - 1, memo))
  }
  memo[i, j] <<- result
  return(result)
}

longest_common_subsequence <- function(seq1, seq2) {
  memo <- matrix(NULL, nrow = length(seq1) + 1, ncol = length(seq2) + 1)
  return(align(seq1, seq2, nchar(seq1), nchar(seq2), memo))
}

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  cat(longest_common_subsequence(strsplit(seq1, NULL)[[1]], strsplit(seq2, NULL)[[1]]), "\n")
}

main()