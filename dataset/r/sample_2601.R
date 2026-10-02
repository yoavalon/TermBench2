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
    calculate_matrix = function() {
      for (i in 1:nchar(.self$seq1)) {
        for (j in 1:nchar(.self$seq2)) {
          match <- .self$matrix[i, j] + ifelse(substr(.self$seq1, i, i) == substr(.self$seq2, j, j), 1, -1)
          delete <- .self$matrix[i, j + 1] - 1
          insert <- .self$matrix[i + 1, j] - 1
          .self$matrix[i + 1, j + 1] <- max(match, delete, insert)
        }
      }
    },
    traceback = function() {
      i <- nchar(.self$seq1)
      j <- nchar(.self$seq2)
      align1 <- ""
      align2 <- ""
      while (i > 0 && j > 0) {
        if (.self$matrix[i + 1, j + 1] == .self$matrix[i, j + 1] - 1) {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0("-", align2)
          i <- i - 1
        } else if (.self$matrix[i + 1, j + 1] == .self$matrix[i + 1, j] - 1) {
          align1 <- paste0("-", align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
          j <- j - 1
        } else {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
          i <- i - 1
          j <- j - 1
        }
      }
      while (i > 0) {
        align1 <- paste0(substr(.self$seq1, i, i), align1)
        align2 <- paste0("-", align2)
        i <- i - 1
      }
      while (j > 0) {
        align1 <- paste0("-", align1)
        align2 <- paste0(substr(.self$seq2, j, j), align2)
        j <- j - 1
      }
      return(list(align1, align2))
    }
  )
)

main <- function() {
  seq1 <- "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"
  seq2 <- "GTCGTTCGGAATGCCGTTGCTCTGTAAA"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$calculate_matrix()
  aligned_seq1 <- aligner$traceback()[[1]]
  aligned_seq2 <- aligner$traceback()[[2]]
  cat("Aligned Sequence 1:", aligned_seq1, "\n")
  cat("Aligned Sequence 2:", aligned_seq2, "\n")
}

main()