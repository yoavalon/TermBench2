SequenceAligner <- setRefClass("SequenceAligner",
                              fields = list(
                                seq1 = "character",
                                seq2 = "character",
                                score_matrix = "matrix",
                                trace_matrix = "matrix"
                              ),
                              methods = list(
                                initialize = function(seq1, seq2) {
                                  seq1 <<- seq1
                                  seq2 <<- seq2
                                  score_matrix <<- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
                                  trace_matrix <<- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
                                },
                                
                                fill_matrices = function() {
                                  for (i in 1:nchar(seq1)) {
                                    for (j in 1:nchar(seq2)) {
                                      match <- score_matrix[i, j] + ifelse(substr(seq1, i, i) == substr(seq2, j, j), 1, 0)
                                      delete <- score_matrix[i - 1, j] - 1
                                      insert <- score_matrix[i, j - 1] - 1
                                      score_matrix[i + 1, j + 1] <<- max(match, delete, insert)
                                      if (score_matrix[i + 1, j + 1] == match) {
                                        trace_matrix[i + 1, j + 1] <<- 1
                                      } else if (score_matrix[i + 1, j + 1] == delete) {
                                        trace_matrix[i + 1, j + 1] <<- 2
                                      } else {
                                        trace_matrix[i + 1, j + 1] <<- 3
                                      }
                                    }
                                  }
                                },
                                
                                trace_back = function() {
                                  i <- nchar(seq1)
                                  j <- nchar(seq2)
                                  aligned_seq1 <- c()
                                  aligned_seq2 <- c()
                                  while (i > 0 & j > 0) {
                                    if (trace_matrix[i + 1, j + 1] == 1) {
                                      aligned_seq1 <- c(substr(seq1, i, i), aligned_seq1)
                                      aligned_seq2 <- c(substr(seq2, j, j), aligned_seq2)
                                      i <<- i - 1
                                      j <<- j - 1
                                    } else if (trace_matrix[i + 1, j + 1] == 2) {
                                      aligned_seq1 <- c(substr(seq1, i, i), aligned_seq1)
                                      aligned_seq2 <- c('-', aligned_seq2)
                                      i <<- i - 1
                                    } else {
                                      aligned_seq1 <- c('-', aligned_seq1)
                                      aligned_seq2 <- c(substr(seq2, j, j), aligned_seq2)
                                      j <<- j - 1
                                    }
                                  }
                                  cat('Aligned Sequence 1:', paste(aligned_seq1, collapse = ""), "\n")
                                  cat('Aligned Sequence 2:', paste(aligned_seq2, collapse = ""), "\n")
                                }
                              ))

main <- function() {
  seq1 <- 'AGGTAB'
  seq2 <- 'GXTXAYB'
  aligner <- SequenceAligner(seq1, seq2)
  aligner$fill_matrices()
  aligner$trace_back()
}

main()