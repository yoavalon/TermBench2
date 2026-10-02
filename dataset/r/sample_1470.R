SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    matrix = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
      .self$matrix <- matrix(0, nrow = nchar(seq1) + 1, ncol = nchar(seq2) + 1)
    },
    fill_matrix = function() {
      for (i in 1:nchar(.self$seq1)) {
        for (j in 1:nchar(.self$seq2)) {
          match <- .self$matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, -1)
          delete <- .self$matrix[i, j + 1] - 1
          insert <- .self$matrix[i + 1, j] - 1
          .self$matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    backtrack = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      aligned_seq1 <- ""
      aligned_seq2 <- ""
      while (i > 0 | j > 0) {
        if (i > 0 & j > 0 & .self$matrix[i + 1, j + 1] == .self$matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, -1)) {
          aligned_seq1 <- paste0(substr(.self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- paste0(substr(.self$seq2, j, j), aligned_seq2)
          i <- i - 1
          j <- j - 1
        } else if (i > 0 & .self$matrix[i + 1, j + 1] == .self$matrix[i, j + 1] - 1) {
          aligned_seq1 <- paste0(substr(.self$seq1, i, i), aligned_seq1)
          aligned_seq2 <- paste0("-", aligned_seq2)
          i <- i - 1
        } else {
          aligned_seq1 <- paste0("-", aligned_seq1)
          aligned_seq2 <- paste0(substr(.self$seq2, j, j), aligned_seq2)
          j <- j - 1
        }
      }
      return(list(aligned_seq1, aligned_seq2))
    }
  )
)

main <- function() {
  seq1 <- "ACGTGACGTG"
  seq2 <- "ACGTTACGTG"
  aligner <- SequenceAligner(seq1, seq2)
  aligner$fill_matrix()
  aligned_seq1 <- aligner$backtrack()[[1]]
  aligned_seq2 <- aligner$backtrack()[[2]]
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()