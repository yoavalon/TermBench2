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
    build_matrix = function() {
      for (i in 0:nchar(.self$seq1)) {
        for (j in 0:nchar(.self$seq2)) {
          if (i == 0 || j == 0) {
            .self$matrix[i + 1, j + 1] <- 0
          } else if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
            .self$matrix[i + 1, j + 1] <- .self$matrix[i, j] + 1
          } else {
            .self$matrix[i + 1, j + 1] <- max(.self$matrix[i, j + 1], .self$matrix[i + 1, j])
          }
        }
      }
    },
    trace_back = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      align1 <- ""
      align2 <- ""
      while (i > 0 && j > 0) {
        if (substr(.self$seq1, i, i) == substr(.self$seq2, j, j)) {
          align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
          align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
          i <- i - 1
          j <- j - 1
        } else if (.self$matrix[i, j + 1] > .self$matrix[i + 1, j]) {
          align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
          align2 <- paste("-", align2, sep = "")
          i <- i - 1
        } else {
          align1 <- paste("-", align1, sep = "")
          align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
          j <- j - 1
        }
      }
      while (i > 0) {
        align1 <- paste(substr(.self$seq1, i, i), align1, sep = "")
        align2 <- paste("-", align2, sep = "")
        i <- i - 1
      }
      while (j > 0) {
        align1 <- paste("-", align1, sep = "")
        align2 <- paste(substr(.self$seq2, j, j), align2, sep = "")
        j <- j - 1
      }
      return(list(align1 = align1, align2 = align2))
    }
  )
)

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$build_matrix()
  aligned_seq1 <- aligner$trace_back()$align1
  aligned_seq2 <- aligner$trace_back()$align2
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()